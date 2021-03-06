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
#include <iostream>

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
        char* charPointer = this->argv[1];
        while (*charPointer != '\0') {
            if (*charPointer < '0' || *charPointer > '9') {
                std::cout << "error: the second argument on command line is not a number" << std::endl;
                std::exit(EXIT_FAILURE);
            }
            charPointer++;
        }
        try {
            umpteenth = atoi(this->argv[1]);
        } catch (const std::overflow_error& overflowError) {
            std::cout << "error: overflow" << std::endl;
            std::exit(EXIT_FAILURE);
        } catch (const std::runtime_error& runtimeError) {
            std::cout << "error: runtime" << std::endl;
            std::exit(EXIT_FAILURE);
        } catch (const std::exception& exception) {
            std::cout << "exception" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    } else {
        std::cout << "oversight: please enter a number after the command" << std::endl;
    }
    return umpteenth;
}
