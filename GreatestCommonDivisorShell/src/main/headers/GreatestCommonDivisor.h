/*
 * GreatestCommonDivisor.h
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

#include <iostream>
#include <vector>

#ifndef GREATESTCOMMONDIVISOR_H
#define GREATESTCOMMONDIVISOR_H

namespace paolomococci {

class GreatestCommonDivisor {
public:
	GreatestCommonDivisor();
	virtual ~GreatestCommonDivisor();
	bool setValues(std::vector<double> values);
	void showValues();
	void computeGreatestCommonDivisor();
	long getGreatestCommonDivisor();
private:
	long gcd(long argOne, long argTwo);
	std::vector<long> values;
	long greatestCommonDivisor = 1L;
};

}

#endif
