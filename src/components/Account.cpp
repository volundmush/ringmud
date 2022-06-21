//
// Created by volund on 6/20/22.
//

#include "components/Account.h"

namespace ring::components {

    Account::Account() = default;


    nlohmann::json Account::serialize() const {
        nlohmann::json j;
        if(!name.empty()) j["name"] = name;
        if(!email.empty()) j["email"] = email;
        if(!pass.empty()) j["pass"] = pass;
        if(!account_id.empty()) j["account_id"] = account_id;
        if(rpp) j["rpp"] = rpp;
        if(total) j["total"] = total;
        if(slots) j["slots"] = slots;
        if(level) j["level"] = level;
        if(custom) j["custom"] = custom;
        return j;
    }

    void Account::loadJson(const nlohmann::json &j) {
        if(j.contains("name")) name = j["name"];
        if(j.contains("email")) email = j["email"];
        if(j.contains("pass")) pass = j["pass"];
        if(j.contains("account_id")) account_id = j["account_id"];
        if(j.contains("rpp")) rpp = j["rpp"];
        if(j.contains("total")) total = j["total"];
        if(j.contains("slots")) slots = j["slots"];
        if(j.contains("level")) level = j["level"];
        if(j.contains("custom")) custom = j["custom"];
    }

}