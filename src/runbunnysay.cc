/*
* bunnysay
*
*  Created on: 2015-11-30
*      Author: brad
*
*   This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/
#include "bunnysay.h"
#include <iostream>
#include <iterator>
#include <string>

void usage(char *prog) {
  std::cout << "Usage: " + std::string(prog) + " [--] [WORDS]\n" +
    "\t--\tSpecifies that text will be read from standard in\n" +
    "\t[WORDS]\t Specifies the words that will be used, obviously, the first" +
    " cannot be \"--\"" << std::endl;
}

int main(int argc, char **argv) {
  std::string buff;
  if (argc >= 2 && std::string(argv[1]) == "--") {
    std::istream_iterator<char> it(std::cin);
    std::istream_iterator<char> end;
    buff = std::string(it, end);
  } else if (argc >= 2) {
    for (int i = 1; i < argc; i++) {
      if (i != 1) {
        buff += " ";
      }
      buff += std::string(argv[i]);
    }
  } else {
    usage(*argv);
    return 0;
  }
  std::cout << bunnyify(buff);
}
