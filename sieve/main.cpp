/*
 * main.cpp
 * 
 * Copyright (C) 2019 paolo mococci
 * 
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "system.h"

using namespace std;
using namespace pm;

int main(int argc, char** argv) {
    
    pm::Shell shell(argc, argv);
    pm::Sieve sieve;
    sieve.sift(shell.verify());

    std::exit(EXIT_SUCCESS);
}
