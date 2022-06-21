//
// Created by volund on 11/25/21.
//

#ifndef RINGMUD_SYSDEP_H
#define RINGMUD_SYSDEP_H


#define CIRCLE_GNU_LIBC_MEMORY_TRACK	0	/* 0 = off, 1 = on */

// Some C libraires
#include <cstdio>
#include <cctype>
#include <cstdarg>
#include <cstdint>
#include <cstring>
#include <strings.h>
#include <cstdlib>
#include <sys/types.h>
#include <unistd.h>
#include <climits>
#include <cerrno>
#include <crypt.h>
#include <sys/time.h>
#include <ctime>
#include <cassert>
#include <zlib.h>
#include <sys/select.h>
#include <fcntl.h>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <csignal>
#include <sys/uio.h>
#include <sys/stat.h>
#include <cstddef>
#include <dirent.h>
#include <linux/limits.h>

#include <bsd/string.h>

// C++ STD libraries
#include <string>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <algorithm>
#include <set>
#include <random>
#include <chrono>
#include <fstream>
#include <stdexcept>
#include <bitset>

#if __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#elif __has_include(<experimental/filesystem>)
#include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;
#else
#error "no filesystem support ='("
#endif

#if __has_include(<optional>)
#include <optional>
#define opt_type std::optional
#elif __has_include(<experimental/optional>)
#include <experimental/optional>
#define opt_type std::experimental::optional
#else
#error "no optional support ='("
#endif

// non-standard libraries
#include "fmt/core.h"
#include "nlohmann/json.hpp"
#include "boost/algorithm/string.hpp"
#include "boost/algorithm/string_regex.hpp"
#include "boost/regex.hpp"

#include "entt/entt.hpp"


#include "clamped.h"



/* Basic system dependencies *******************************************/
#if CIRCLE_GNU_LIBC_MEMORY_TRACK && !defined(HAVE_MCHECK_H)
#error "Cannot use GNU C library memory tracking without <mcheck.h>"
#endif


/* Various virtual (human-reference) number types. */
using vnum = int64_t;
using room_vnum = vnum;
using obj_vnum = vnum;
using mob_vnum = vnum;
using zone_vnum = vnum;
using shop_vnum = vnum;
using trig_vnum = vnum;
using guild_vnum = vnum;
using house_vnum = vnum;

/* Various real (array-reference) number types. */

using gravity_t = uint64_t;
using unique_t = int64_t;
using weight_t = uint64_t;
using height_t = uint64_t;
using abil_t = int16_t;
using skill_t = int8_t;
using skill_id_t = int16_t;
using transform_t = uint8_t;
using item_type_t = int;
using condition_t = int8_t;
using practice_session_t = int64_t;
using practice_clamped_t = clamped<practice_session_t, 0, 5000000000000>;
using abil_train_t = int64_t;
using wimpy_t = clamped<uint8_t, 0, 100>;
using admin_t = int16_t;
using power_t = int64_t;
using power_clamped_t = clamped<power_t, 0, 5000000000000>;
using money_t = uint64_t;
using money_clamped_t =  clamped<money_t, 0, 5000000000000>;
using appearnce_t = uint8_t;
using alignment_t = clamped<int16_t, -1000, 1000>;
using experience_t = int64_t;
using experience_clamped_t = clamped<experience_t, 0, 5000000000000>;
using coordinate_t = float;

using entity_t = entt::entity;

#define strtovnum(num) std::strtoul((num), nullptr, 10);

class char_data;
class obj_data;
class room_data;

typedef std::shared_ptr<char_data> char_sptr;
typedef std::shared_ptr<obj_data> obj_sptr;
typedef std::shared_ptr<room_data> room_sptr;
typedef std::weak_ptr<char_data> char_wptr;
typedef std::weak_ptr<room_data> room_wptr;
typedef std::weak_ptr<obj_data> obj_wptr;

struct command_arguments;

#define CMDARGS (entity_t ch, const command_arguments& argument, int cmd, int subcmd)
#define ACMD(name) void (name)CMDARGS
typedef void(*cmd_t)CMDARGS;
#define SPECIAL(name) int (name)(entity_t, void *me, int cmd, const command_arguments& argument)


class GameDBException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class CommandException: public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class DgScriptException: public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

class DgScriptVarException: public DgScriptException {
public:
    using DgScriptException::DgScriptException;
};

struct input_data {
    std::string cmd;
    opt_type<std::string> conn_id;
    opt_type<std::string> session_id;
};

#endif //RINGMUD_SYSDEP_H
