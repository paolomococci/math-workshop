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

Shell::Shell() {}

Shell::Shell(int argc, char **argv) {
	this->argIndex = argc;
	this->argVector = argv;
}

Shell::~Shell() {}

void Shell::setArgIndex(int argc) {
	this->argIndex = argc;
}

void Shell::setArgVector(char** argv) {
	this->argVector = argv;
}

int Shell::getArgIndex() {
	return this->argIndex;
}

char** Shell::getArgVector() {
	return this->argVector;
}

void Shell::parsing() {
	if (this->argIndex > 1) {
		for (int index = 1; index < this->argIndex; ++index) {
			this->tokens.push_back(std::string(this->argVector[index]));
		}
		for (auto token : tokens) {
			try {
				this->values.push_back(std::stod(token));
			} catch (const std::invalid_argument& invalidArgument) {
				std::cerr
					<< "error: invalid argument "
					<< invalidArgument.what()
					<< " at least one argument passed to MuSigmaShell is not a number"
					<< std::endl;
				std::exit(EXIT_FAILURE);
			}
		}
	} else {
		std::cout
			<< "oversight: please, enter a number series after the command"
			<< std::endl;
	}
}

void Shell::show() {
	std::vector<double>::iterator valuesIterator;
	valuesIterator = this->values.begin();
	std::cout << '{';
	while (valuesIterator != this->values.end()) {
		std::cout << *valuesIterator;
		++valuesIterator;
		if (valuesIterator != this->values.end()) {
			std::cout << ',';
		}
	}
	std::cout << '}' << std::endl;
}

std::vector<double> Shell::getValues() {
	return this->values;
}

std::vector<double>::iterator Shell::getIteratorOfValues() {
	return this->values.begin();
}

}
