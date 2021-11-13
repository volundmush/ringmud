//
// Created by volund on 11/12/21.
//

#include "telnet.h"
#include "net.h"

namespace ring::telnet {
    namespace codes {

        const uint8_t NUL = 0, BEL = 7, CR = 13, LF = 10, SGA = 3, TELOPT_EOR = 25, NAWS = 31;
        const uint8_t LINEMODE = 34, EOR = 239, SE = 240, NOP = 241, GA = 249, SB = 250;
        const uint8_t WILL = 251, WONT = 252, DO = 253, DONT = 254, IAC = 255, MNES = 39;
        const uint8_t MXP = 91, MSSP = 70, MCCP2 = 86, MCCP3 = 87, GMCP = 201, MSDP = 69;
        const uint8_t MTTS = 24;
    }

    TelnetMessage::TelnetMessage(TelnetMsgType m_type) {
        msg_type = m_type;
    }

    std::optional<TelnetMessage> parse_message(asio::streambuf &buf) {
        using namespace ring::telnet::codes;
        // return early if nothing to do.
        auto available = buf.size();
        if(!available) return {};

        // So we do have some data?
        auto box = buf.data();
        auto begin = asio::buffers_begin(box), end = asio::buffers_end(box);
        std::optional<TelnetMessage> response;
        bool escaped = false, match1 = false, match2 = false;

        // first, we read ahead
        if((uint8_t)*begin == IAC) {
            // If it begins with an IAC, then it's a Command, Negotiation, or Subnegotiation
            if(available < 2) {
                return {}; // not enough bytes available - do nothing;
            }
            // we have 2 or more bytes!
            auto b = begin;
            b++;
            auto sub = b;
            uint8_t option = 0;

            switch((uint8_t)*b) {
                case WILL:
                case WONT:
                case DO:
                case DONT:
                    // This is a negotiation.
                    if(available < 3) return {}; // negotiations require at least 3 bytes.
                    response.emplace(TelnetMsgType::Negotiation);
                    response.value().codes[0] = *b;
                    response.value().codes[1] = *(++b);
                    buf.consume(3);
                    return response;
                case SB:
                    // This is a subnegotiation. We need at least 5 bytes for it to work.
                    if(available < 5) return {};

                    option = *(++b);
                    sub = ++b;
                    // we must seek ahead until we have an unescaped IAC SE. If we don't have one, do nothing.

                    while(b != end) {
                        switch((uint8_t)*b) {
                            case IAC:
                                if(match1) {
                                    escaped = true;
                                    match1 = false;
                                } else {
                                    match1 = true;
                                }
                                break;
                            case SB:
                                if(!match1) {
                                    break;
                                }
                                // we have a winner!;
                                b--;
                                response.emplace(TelnetMsgType::Subnegotiation);
                                response.value().codes[0] = option;
                                std::copy(sub, b, response.value().data.begin());
                                buf.consume(5 + response.value().data.size());
                                return response;
                        }
                    }
                    // if we finished the while loop, we don't have enough data, so...
                    return {};
                default:
                    // if it's any other kind of IAC, it's a Command.
                    response.emplace(TelnetMsgType::Command);
                    response.value().data.push_back((uint8_t)*(++b));
                    buf.consume(2);
                    return response;
            };
        } else {
            // Data begins on something that isn't an IAC. Scan ahead until we reach one...
            // Send all data up to an IAC, or everything if there is no IAC, as data.
            response.emplace(TelnetMsgType::AppData);
            auto check = std::find(begin, end, IAC);
            std::copy(begin, check, response.value().data.begin());
            buf.consume(response.value().data.size());
            return response;
        }
    }

    TelnetOption::TelnetOption(TelnetProtocol &prot, uint8_t code) : protocol(prot) {
        this->code = code;
    }

    uint8_t TelnetOption::opCode() const {
        return code;
    }

    bool TelnetOption::startDo() const {
        using namespace codes;
        switch(code) {
            case NAWS:
            case MTTS:
                return true;
            default:
                return false;
        }
    }

    bool TelnetOption::supportLocal() const {
        using namespace codes;
        switch(code) {
            //case MCCP2:
            case MSSP:
            case SGA:
            case MSDP:
            case GMCP:
            //case MXP:
                return true;
            default:
                return false;
        }
    }

    bool TelnetOption::supportRemote() const {
        using namespace codes;
        switch(code) {
            case NAWS:
            case MTTS:
                return true;
            default:
                return false;
        }
    }

    bool TelnetOption::startWill() const {
        using namespace codes;
        switch(code) {
            //case MCCP2:
            case MSSP:
            case SGA:
            case MSDP:
            case GMCP:
            //case MXP:
                return true;
            default:
                return false;
        }
    }

    bool TelnetOption::isReady() const {
        return ready;
    }

    TelnetProtocol::TelnetProtocol(entt::entity ent) {
        using namespace codes;
        entity = ent;

        for(const auto &code : {MSSP, SGA, MSDP, GMCP, NAWS, MTTS}) {
            handlers.emplace(code, TelnetOption(*this, code));
        }
    }

    void TelnetProtocol::onConnect() {
        using namespace codes;
        for(auto &h : handlers) {
            if(h.second.startWill()) {
                h.second.local.negotiating = true;
                sendNegotiate(WILL, h.first);
            }
            if(h.second.startDo()) {
                h.second.remote.negotiating = true;
                sendNegotiate(DO, h.first);
            }
        }
    }

    void TelnetProtocol::sendBytes(const std::vector<uint8_t> &data) {
        auto &details = ring::net::connections.get<ring::net::client_details>(entity);

        if(details.clientType == ring::net::TcpTelnet || details.clientType == ring::net::TlsTelnet) {
            auto &buffers = ring::net::connections.get<ring::net::socket_buffers>(entity);
            auto prep = buffers.out_buffer.prepare(data.size());
            memcpy(prep.data(), data.data(), data.size());
            buffers.out_buffer.commit(data.size());
        }
    }

}