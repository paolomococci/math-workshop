/*
 * Mu.cpp
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

#include "Mu.h"

namespace paolomococci {

Mu::Mu() {}

Mu::~Mu() {}

bool Mu::setValues(std::vector<double> values) {
	this->values = values;
	return !(this->values.empty());
}

void Mu::showValues() {
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

void Mu::computeAverage() {
	std::vector<double>::iterator valuesIterator;
	valuesIterator = this->values.begin();
	while (valuesIterator != this->values.end()) {
		this->average += *valuesIterator;
		++valuesIterator;
	}
	this->average /= this->values.size();
}

double Mu::getAverage() {
	return this->average;
}

}
