//
// Created by volund on 6/20/22.
//

#include "core.h"
#include <iostream>
#include "boost/program_options.hpp"

int main(int argc, char* argv[]) {
    namespace po = boost::program_options;

    cwd = fs::current_path();

    std::string l_dir = "legacy", b_dir = "backups", lo_dir = "logs", s_dir = "save";
    uint16_t d_port = 1280;

    po::options_description desc("Allowed Options");
    desc.add_options()
            ("help,h", "produce help message")
            ("legacy,ld", po::value<std::string>(&l_dir), "set legacy directory")
            ("log,l", po::value<std::string>(&lo_dir), "set log directory")
    ("backup,b", po::value<std::string>(&b_dir), "set backup directory")
            ("assets,a", po::value<std::string>(&s_dir), "set assets directory")
            ("port,p", po::value<uint16_t>(&d_port), "default port")
;
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);

    if(vm.count("help")) {
        std::cout << desc << std::endl;
        return 0;
    }

    log_dir = vm["log"].as<std::string>();
    legacy_dir = vm["legacy"].as<std::string>();
    asset_dir = vm["assets"].as<std::string>();
    backup_dir = vm["backup"].as<std::string>();

    setup_log("ring.log");



}