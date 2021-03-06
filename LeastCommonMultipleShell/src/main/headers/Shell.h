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

#include <iostream>
#include <string>
#include <vector>

#ifndef SHELL_H
#define SHELL_H

namespace paolomococci {

class Shell {
public:
	Shell();
	Shell(int argc, char** argv);
	virtual ~Shell();
	void setArgIndex(int argc);
	void setArgVector(char** argv);
	int getArgIndex();
	char** getArgVector();
	void parsing();
	void show();
	std::vector<double> getValues();
	std::vector<double>::iterator getIteratorOfValues();
private:
	int argIndex;
	char** argVector;
	std::vector<std::string> tokens;
	std::vector<double> values;
};

}

#endif
