//
// Copyright (C) 2013, Felix Bytow <felix.bytow@googlemail.com>
// 
// This file is part of DragonScript.
// 
// DragonScript is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// DragonScript is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with DragonScript.  If not, see <http://www.gnu.org/licenses/>.
//

#include <iostream>
#include <string>

#include <boost/locale.hpp>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

#include "config.hxx"

void show_version()
{
    std::cout << "DragonScript Version " << ds::config::VERSION_MAJOR << "." << ds::config::VERSION_MINOR << "\n"
              << "Copyright (C) 2013, Felix Bytow <felix.bytow@googlemail.com>\n" << std::endl;

    std::cout << "Git-Hash:    " << ds::config::GIT_HASH << "\n"
              << "Git-Refspec: " << ds::config::GIT_REFSPEC << "\n" << std::endl;

    std::cout << "Build-Type:  " << ds::config::BUILD_TYPE << "\n"
              << "Prefix:      " << ds::config::INSTALL_PREFIX << "\n" << std::endl;
}

int main(int argc, char ** argv)
{
    using namespace std;
    using namespace boost::locale;
    using namespace boost::program_options;
    using namespace boost::filesystem;

    ////////////////////
    // prepare locale //
    ////////////////////
    locale::global(locale(""));

    generator   gen;

    // path prefix(ds::config::INSTALL_PREFIX);
    // gen.add_messages_path((prefix / "share" / "ds").native());
    gen.add_messages_path(".");
    gen.add_messages_domain("messages");

    // locale loc = locale();
    // cout << loc.name() << endl;

    // locale syslocale = gen(loc.name());
    // locale::global(syslocale);

    // cout.imbue(syslocale);

    // cout << syslocale.name() << endl;
    locale::global(gen(""));
    cout.imbue(locale());

    //////////////////////////
    // command line options //
    //////////////////////////
    options_description desc(gettext<char>("Allowed options").c_str());
    desc.add_options()
        ("help,?",    gettext<char>("produce help message").c_str())
        ("version,v", gettext<char>("show version information").c_str())
    ;

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        return 0;
    }

    if (vm.count("version"))
    {
        show_version();
        return 0;
    }

    return 0;
}
