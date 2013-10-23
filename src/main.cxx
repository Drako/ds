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

#include "config.hxx"

int main(int argc, char ** argv)
{
    std::cout << "DragonScript Version " << ds::config::VERSION_MAJOR << "." << ds::config::VERSION_MINOR << "\n"
              << "Copyright (C) 2013, Felix Bytow <felix.bytow@googlemail.com>\n" << std::endl;

    std::cout << "Git-Hash:    " << ds::config::GIT_HASH << "\n"
              << "Git-Refspec: " << ds::config::GIT_REFSPEC << "\n" << std::endl;

    return 0;
}
