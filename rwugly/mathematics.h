/*
 * mathematics.h
 *
 * Copyright (C) 2012 paolo mococci
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

/* prototype of functions */
#ifndef MATHEMATICS_H
#define MATHEMATICS_H

long double Logistic(long double *);
unsigned long long int GetIgnition(long double *);

/* definition of functions */
long double Logistic(long double *x) {
    long double r = 3.57;
    long double temp = 0;

    temp = (long double) 1 - *x;
    temp *= *x;
    temp *= r;

    return temp;
}

unsigned long long int GetIgnition(long double *x) {

    union number {
        long double R;
        unsigned long long int N;
    } ignition;

    ignition.R = *x;

    return ignition.N;
}

#endif
