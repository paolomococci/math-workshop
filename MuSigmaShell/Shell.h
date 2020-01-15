/*
 * Shell.h
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

#include <cstdlib>
#include <iostream>
#include <vector>

#ifndef SHELL_H_
#define SHELL_H_

namespace paolomococci {

class Shell {
public:
	Shell(int argc, char** argv);
	virtual ~Shell();
	Shell(const Shell &other);
	Shell(Shell &&other);
	Shell& operator=(const Shell &other);
	Shell& operator=(Shell &&other);
	int getArgIndex();
	char** getArgVector();
	void verify();
	std::vector<double> getValues();
	void errorNaN();
	void error(char* error);
private:
	int argIndex;
	char** argVector;
	std::vector<double> values;
};

}

#endif
