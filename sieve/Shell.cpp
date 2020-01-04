/*
 * Shell.cpp
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

#include "Shell.h"
#include <cstdlib>

using namespace pm;

Shell::Shell() {
}

Shell::Shell(int nth, char** args) {
    this->argc = nth;
    this->argv = args;
}

Shell::Shell(const Shell& orig) {
}

Shell::~Shell() {
}

int Shell::getArgc() {
    return this->argc;
}

char** Shell::getArgv() {
    return this->argv;
}

void Shell::setArgc(int nth) {
    this->argc = nth;
}

void Shell::setArgv(char** args) {
    this->argv = args;
}

unsigned long Shell::verify() {
    unsigned long umpteenth = 0UL;
    if (this->argc == 2) {
        bool isNumber = false;
        char* charPointer = this->argv[1];
        while (*charPointer != '\0') {
            if (*charPointer < '0' || *charPointer > '9') {
                isNumber = false;
            } else {
                isNumber = true;
            }
        }
        if (isNumber) {
            umpteenth = atoi(this->argv[1]);
        }
    }
    return umpteenth;
}
