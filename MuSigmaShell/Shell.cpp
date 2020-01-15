/*
 * Shell.cpp
 *
 * Copyright (C) 2020 paolo mococci
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

namespace paolomococci {

Shell::Shell(int argc, char **argv) {
	this->argIndex = argc;
	this->argVector = argv;
	this->values = new std::vector<double>;
}

Shell::~Shell() {
	delete this->values;
}

int Shell::getArgIndex() {
	return this->argIndex;
}

char** Shell::getArgVector() {
	return this->argVector;
}

bool Shell::verify() {
	int dotCount = 0;
	bool check = true;
	// TODO
	return check;
}

std::vector<double> Shell::getValues() {
	return this->values;
}

void Shell::errorNaN() {
	std::cout
		<< "error: the second argument on command line is not a number"
		<< std::endl;
	std::exit(EXIT_FAILURE);
}

void Shell::error(char* error) {
	std::cout << error << std::endl;
	std::exit(EXIT_FAILURE);
}

}
