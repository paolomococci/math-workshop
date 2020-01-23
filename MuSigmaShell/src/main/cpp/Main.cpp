/*
 * Main.cpp
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

#include "Main.h"

namespace paolomococci {

Main::Main() {}

Main::~Main() {}

void Main::setArgIndex(int argc) {
	this->argIndex = argc;
}
void Main::setArgVector(char** argv) {
	this->argVector = argv;
}

bool Main::execute() {
	bool check = false;
	this->shell.setArgIndex(this->argIndex);
	this->shell.setArgVector(this->argVector);
	this->shell.parsing();
	check = (
		this->mu.setValues(this->shell.getValues()) &&
		this->sigma.setValues(this->shell.getValues())
	);
	this->mu.computeAverage();
	this->sigma.computeStandardDeviation();
	return check;
}

void Main::showMuValue() {
	std::cout << "average: " << this->mu.getAverage() << std::endl;
}
void Main::showSigmaValue() {
	std::cout << "standard deviation: " << this->sigma.getStandardDeviation() << std::endl;
}

}
