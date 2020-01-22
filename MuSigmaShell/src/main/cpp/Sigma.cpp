/*
 * Sigma.cpp
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

#include "Sigma.h"

namespace paolomococci {

Sigma::Sigma() {}

Sigma::~Sigma() {
}

bool Sigma::setValues(std::vector<double> values) {
	this->values = values;
	return !(this->values.empty());
}

void Sigma::computeStandardDeviation() {
	std::vector<double>::iterator valuesIterator;
	valuesIterator = this->values.begin();
	double numerosity = (double) this->values.size();
	double temp = 0.0;
	double tempAverage = 0.0;
	while (valuesIterator != this->values.end()) {
		tempAverage += *valuesIterator;
		temp += std::pow(*valuesIterator, 2.0) / numerosity;
		++valuesIterator;
	}
	tempAverage /= numerosity;
	this->standardDeviation = std::sqrt(temp - tempAverage * tempAverage);
}

double Sigma::getStandardDeviation() {
	return this->standardDeviation;
}

}
