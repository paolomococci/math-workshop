/*
 * SieveTests.cpp
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

#include <stdlib.h>
#include <iostream>

using namespace std;

void SampleTestOne() {
    std::cout << "SampleTestOne" << std::endl;
}

void SampleTestTwo() {
    std::cout << "SampleTestTwo" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testName=SampleTestTwo (SampleTestOne) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% SampleTestOne" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% SampleTestOne (SampleTestOne)" << std::endl;
    SampleTestOne();
    std::cout << "%TEST_FINISHED% time=0 SampleTestOne (SampleTestOne)" << std::endl;

    std::cout << "%TEST_STARTED% SampleTestTwo (SampleTestOne)\n" << std::endl;
    SampleTestTwo();
    std::cout << "%TEST_FINISHED% time=0 SampleTestTwo (SampleTestOne)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}
