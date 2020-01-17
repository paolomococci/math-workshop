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
}

Shell::~Shell() {

}

int Shell::getArgIndex() {
	return this->argIndex;
}

char** Shell::getArgVector() {
	return this->argVector;
}

void Shell::verify() {
	int dotCount = 0;
	if (this->argIndex > 1) {
		for (int index = 1; index < this->argIndex; index++) {
			char *charPointer = this->argVector[index];
			while (*charPointer != '\0') {
				switch (*charPointer) {
					case '.':
						dotCount++;
						charPointer++;
						break;
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
						charPointer++;
						break;
					default:
						this->errorNaN();
						break;
				}
				if (dotCount > 1) this->errorNaN();
				try {
					this->values.push_back(atof(this->argVector[1]));
				} catch (const std::exception &exception) {
					this->error();
				}
			}
		}
	} else {
		std::cout
			<< "oversight: please enter a number after the command"
			<< std::endl;
	}
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

void Shell::error() {
	std::cout << "error: exception" << std::endl;
	std::exit(EXIT_FAILURE);
}

}
