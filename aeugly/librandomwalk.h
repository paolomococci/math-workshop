/*
 * librandomwalk.h
 *
 * Copyright (C) 2012 paolo mococci
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* no use value over 18000000000000000000ULL */
#ifndef LIBRANDOMWALK_H
#define LIBRANDOMWALK_H

#define ESCAPE_ROUND 1000000000000ULL

/* definition of integer128 */
typedef struct _integer128 {
    unsigned long long int head;
    unsigned long long int tail;
} integer128;

/* definition of bitVector union type */
typedef union _bitVector {
    integer128 vectorInt128;
    long double vectorLongDouble;
    unsigned long long int vectorInt64;
} bitVector;

/* extern function */
extern void Riddle(int *, int *);
extern ae GetAENumber(unsigned long long int *);

/* prototype of functions */
unsigned long long int Crucible(integer128 *);
ae Move(unsigned long long int *);
int Trace(double *, unsigned long long int *, unsigned long long int *);
void RandomWalk(int *, int *, int *, unsigned long long int *, unsigned long long int *);

/* definition of functions */
unsigned long long int Crucible(integer128 *vectorOfInt128) {
    unsigned long long int tempInt64 = 0;

    tempInt64 = (unsigned long long int) (vectorOfInt128->head ^ vectorOfInt128->tail);

    return tempInt64;
}

ae Move(unsigned long long int *shiftRegister) {
    ae moveNumber;
    ae aeNumber;

    moveNumber.x = 0.0;
    moveNumber.y = 0.0;

    aeNumber.x = 0.0;
    aeNumber.y = 0.0;

    aeNumber = GetAENumber(shiftRegister);

    if (aeNumber.x < 0.5) {
        moveNumber.x = -0.001;
    } else {
        moveNumber.x = 0.001;
    }

    if (aeNumber.y < 0.5) {
        moveNumber.y = -0.001;
    } else {
        moveNumber.y = 0.001;
    }

    return moveNumber;
}

int Trace(double *vectorOfFrequencyNormalized,
        unsigned long long int *shiftRegister,
        unsigned long long int *shiftRegisterEntropy) {
    ae traceBindNumber;
    ae tempBindNumber;
    bitVector alphaNumber;
    int aleatoryBindNumber = 0;
    unsigned int control = 1;
    unsigned long long int tempAleatoryBindNumber = 0;
    unsigned long long int escapeRound = 0;

    traceBindNumber.x = 0.0;
    traceBindNumber.y = 0.0;

    tempBindNumber.x = 0.0;
    tempBindNumber.y = 0.0;

    alphaNumber.vectorLongDouble = 0.0;

    traceBindNumber = GetAENumber(shiftRegister);

    alphaNumber.vectorLongDouble = traceBindNumber.x;

    tempAleatoryBindNumber = Crucible(&alphaNumber.vectorInt128);

    aleatoryBindNumber = (int) (tempAleatoryBindNumber % MODALITY);

    do {
        escapeRound++;

        if (escapeRound > ESCAPE_ROUND) {
            puts("Error: out of time");
            puts("You have enough experimental data?");

            /* Give back memory space allocated for shift registers */
            GiveBackMemorySpace(shiftRegisterEntropy);
            GiveBackMemorySpace(shiftRegister);

            exit(EXIT_FAILURE);
        }

        tempBindNumber = Move(shiftRegister);

        traceBindNumber.x += tempBindNumber.x;
        traceBindNumber.y += tempBindNumber.y;

        if (traceBindNumber.y < 0.001) {
            traceBindNumber.y = (long double) 0.999;
        }

        if (traceBindNumber.y > 0.999) {
            traceBindNumber.y = (long double) 0.001;
        }

        if (traceBindNumber.x < -0.999) {

            aleatoryBindNumber -= 1;
            traceBindNumber.x = (long double) 0.000;

            if (aleatoryBindNumber < 0) {
                aleatoryBindNumber = (int) 89;
            }

            if (traceBindNumber.y <= *(vectorOfFrequencyNormalized + aleatoryBindNumber)) {
                control = 0;
            }

        }

        if (traceBindNumber.x > 0.999) {

            aleatoryBindNumber += 1;
            traceBindNumber.x = (long double) 0.000;

            if (aleatoryBindNumber > 89) {
                aleatoryBindNumber = (int) 0;
            }

            if (traceBindNumber.y <= *(vectorOfFrequencyNormalized + aleatoryBindNumber)) {
                control = 0;
            }

        }

    } while (control);

    return aleatoryBindNumber;
}

void RandomWalk(int *vectorOfAleatoryNumbers,
        int *vectorOfFrequency,
        int *numberOfSetOfFive,
        unsigned long long int *shiftRegister,
        unsigned long long int *shiftRegisterEntropy) {
    int i;
    double vectorOfFrequencyNormalized[MODALITY] = {0.0};

    for (i = 0; i < MODALITY; i++) {
        *(vectorOfFrequencyNormalized + i) =
                (double) *(vectorOfFrequency + i) / (double) *numberOfSetOfFive;
    }

    for (i = 0; i < NUMBERS; i++) {

        *(vectorOfAleatoryNumbers + i) = Trace(
                vectorOfFrequencyNormalized,
                shiftRegister,
                shiftRegisterEntropy);

        Riddle(&i, vectorOfAleatoryNumbers);
    }
}

#endif
