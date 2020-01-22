/*
 * Main.h
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

#include "Shell.h"
#include "Mu.h"
#include "Sigma.h"

#ifndef MAIN_H
#define MAIN_H

namespace paolomococci {

class Main {
public:
	Main();
	virtual ~Main();
	void setArgIndex(int argc);
	void setArgVector(char** argv);
	bool execute();
	void showMuValue();
	void showSigmaValue();
private:
	int argIndex;
	char** argVector;
	paolomococci::Shell shell;
	paolomococci::Mu mu;
	paolomococci::Sigma sigma;
};

}

#endif
