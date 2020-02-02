/*
 * GreatestCommonDivisor.cpp
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

#include "GreatestCommonDivisor.h"

namespace paolomococci {

GreatestCommonDivisor::GreatestCommonDivisor() {}

GreatestCommonDivisor::~GreatestCommonDivisor() {}

bool GreatestCommonDivisor::setValues(std::vector<double> values) {
	std::vector<double>::iterator valuesIterator;
	valuesIterator = values.begin();
	while (valuesIterator != values.end()) {
		this->values.push_back((long) *valuesIterator);
		valuesIterator++;
	}
	return !(this->values.empty());
}

void GreatestCommonDivisor::showValues() {
	std::vector<long>::iterator valuesIterator;
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

long GreatestCommonDivisor::gcd(long argOne, long argTwo) {
	if (argTwo == 0) {
		return argOne;
	} else {
		return this->gcd(argTwo, argOne % argTwo);
	}
}

void GreatestCommonDivisor::computeGreatestCommonDivisor() {
	std::vector<long>::iterator valuesIterator;
	valuesIterator = this->values.begin();
	long temp = 1L;
	while (valuesIterator != this->values.end()) {
		temp = this->gcd(*valuesIterator, temp);
		valuesIterator++;
	}
	this->greatestCommonDivisor = temp;
}

long GreatestCommonDivisor::getGreatestCommonDivisor() {
	return this->greatestCommonDivisor;
}

}
