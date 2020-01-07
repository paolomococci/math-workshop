/*
 * Sieve.cpp
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

#include <iostream>
#include <iterator>
#include <vector>

#include "Sieve.h"

using namespace std;

pm::Sieve::Sieve() {
}

pm::Sieve::Sieve(const pm::Sieve& orig) {
}

pm::Sieve::Sieve(pm::Sieve&& orig) {
}

pm::Sieve::~Sieve() {
}

void pm::Sieve::sift(unsigned long nth) {
    try {
        std::vector<bool> booleanSieveVector(++nth, true);
        std::vector<bool>::iterator booleanSieveIterator = booleanSieveVector.begin();
        // TODO
        std::cout << std::endl;
    } catch (const std::range_error& rangeError) {
        std::cout << "error: range" << std::endl;
        std::exit(EXIT_FAILURE);
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
}
