/*
 * test.h
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

#ifndef TEST_H
#define TEST_H

#define CATEGORY 100
#define NUMBER_OF_SAMPLE 131071

/* extern function */
extern unsigned long long int CallShift(unsigned long long int *);

/* prototype of functions for shift register chi-square test */
void Populate(unsigned int *, unsigned long long int *);
void ComputeTemporaryPhi(unsigned long long int *, unsigned int *);
void ComputePhi(long double *, unsigned long long int *);
void ShowPhi(long double *);

/* definition of functions for shift register chi-square test */
void Populate(unsigned int *frequency, unsigned long long int *reg)
{
	int index;
	int bin = 0;
	unsigned long long int tempAleatoryNumber = 0;
	unsigned long long int maxUInt64 = 0;
	long double rho = 0.0;

	maxUInt64 = ~maxUInt64;

	for (index = 0; index < NUMBER_OF_SAMPLE; index++) {
		tempAleatoryNumber = CallShift(reg);
		rho = (long double)tempAleatoryNumber / (long double)maxUInt64;
		bin = (int)(rho * CATEGORY);
		(*(frequency + bin))++;
	}

}

void ComputeTemporaryPhi(unsigned long long int *tempPhi, unsigned int *frequency)
{
	int index;

	for (index = 0; index < CATEGORY; index++) {
		*tempPhi += (*(frequency + index)) * (*(frequency + index));
	}
}

void ComputePhi(long double *phi, unsigned long long int *tempPhi)
{
	*phi = (long double)(*tempPhi) * (long double)CATEGORY;
	*phi /= (long double)NUMBER_OF_SAMPLE;
	*phi -= (long double)NUMBER_OF_SAMPLE;
}

void ShowPhi(long double *phi)
{
	printf("%f\n", (double)(*phi));
}

#endif
