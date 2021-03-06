/*
 * Shell.h
 * 
 * Copyright (C) 2019 paolo mococci
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

#ifndef SHELL_H
#define SHELL_H

namespace pm {
    class Shell;
}

class pm::Shell {
public:
    Shell();
    Shell(int nth, char** args);
    Shell(const pm::Shell& orig);
    virtual ~Shell();
    int getArgc();
    char** getArgv();
    void setArgc(int nth);
    void setArgv(char** args);
    unsigned long verify();
private:
    int argc;
    char** argv;
};

#endif
