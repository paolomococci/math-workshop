/*
 * libaleatory.h
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

/* First nine prime numbers of Mersenne 
 *	M2		3
 * 	M3		7
 * 	M5		31
 * 	M7		127
 * 	M13		8191
 * 	M17		131071
 * 	M19		524287
 */

/*
 * Ecuyer type 1
 *
 *	a = 1181783497276652981
 *	m = 18446744073709551615
 */

/* value definition for shift register functions section */
#ifndef LIBALEATORY_H
#define LIBALEATORY_H

#define OUT_OF 524287
#define SHIFT_LENGTH 131071
#define OFFSET_13 8191
#define OFFSET_7 127
#define OFFSET_5 31
#define OFFSET_3 7
#define OFFSET_2 3
#define OFFSET_ZERO 0

/* define AE Aleatory Environment Number */
typedef struct _ae {
    long double x;
    long double y;
} ae;

typedef union _bitvector {
    long double ld;
    unsigned long long int ulli;
} bitvector;

/* prototype of extern functions */
extern unsigned long long int * GetMemorySpace(int);
extern void GiveBackMemorySpace(unsigned long long int *);

/* prototype of shift register functions section */
unsigned long long int MinimalStandardGCL(unsigned long long int, unsigned long long int, unsigned long long int);
unsigned long long int GetSeed(void);
unsigned long long int GetEntropy(unsigned long long int *);
void EntropyShiftRegisterOutOfTransientRegime(unsigned long long int *);
void OutOfTransientRegime(unsigned long long int *, unsigned long long int *);
void ShiftInit(unsigned long long int *, unsigned long long int *);
void ShiftVacuum(unsigned long long int *);
void ShiftCollider(unsigned long long int *, unsigned long long int *);
unsigned long long int CallShift(unsigned long long int *);
void InitShiftRegisterEntropy(unsigned long long int *, unsigned long long int *);
void InitShiftRegisterWithCollider(unsigned long long int *, unsigned long long int *, unsigned long long int *);
void InitShiftRegisterPlus(unsigned long long int *, unsigned long long int *, unsigned long long int *);
unsigned long long int GetAleatoryULLInt(unsigned long long int *);
long double GetAleatoryLDouble(unsigned long long int *);

/* prototype of function for ae number [0;1]x + [0;1]y */
ae GetAENumber(unsigned long long int *);

/* definition of shift register functions section */
unsigned long long int MinimalStandardGCL(
        unsigned long long int a,
        unsigned long long int aleatoryNumber,
        unsigned long long int m) {
    return ((a * aleatoryNumber) % m);
}

unsigned long long int GetSeed(void) {
    return (unsigned long long int) time(NULL);
}

unsigned long long int GetEntropy(unsigned long long int *shiftRegisterEntropy) {
    unsigned long long int shiftNumber;

    shiftNumber = (unsigned long long int) CallShift(shiftRegisterEntropy);
    shiftNumber = (unsigned long long int) CallShift(shiftRegisterEntropy);
    shiftNumber = (unsigned long long int) CallShift(shiftRegisterEntropy);

    return shiftNumber;
}

void EntropyShiftRegisterOutOfTransientRegime(unsigned long long int *entropyNumber) {
    int i;
    const unsigned long long int a = 1181783497276652981ULL;
    const unsigned long long int module = 18446744073709551615ULL;

    *entropyNumber = GetSeed();

    for (i = 0; i < OUT_OF; i++) {
        *entropyNumber = MinimalStandardGCL(a, *entropyNumber, module);
    }
}

void OutOfTransientRegime(unsigned long long int *aleatoryNumber, unsigned long long int *shiftRegisterEntropy) {
    int i;
    const unsigned long long int a = 1181783497276652981ULL;
    const unsigned long long int module = 18446744073709551615ULL;

    *aleatoryNumber = GetEntropy(shiftRegisterEntropy);

    for (i = 0; i < OUT_OF; i++) {
        *aleatoryNumber = MinimalStandardGCL(a, *aleatoryNumber, module);
    }
}

void ShiftInit(unsigned long long int *aleatoryNumber, unsigned long long int *shiftRegister) {
    int index0;
    int index1;
    unsigned long long int theBit = 0;
    const unsigned long long int a = 1181783497276652981ULL;
    const unsigned long long int module = 18446744073709551615ULL;
    unsigned long long int maxUInt64 = 0;
    long double temp = 0.0;

    maxUInt64 = ~maxUInt64;

    for (index0 = 0; index0 < SHIFT_LENGTH; index0++) {
        for (index1 = 0; index1 < (8 * sizeof (unsigned long long int)); index1++) {
            *aleatoryNumber = MinimalStandardGCL(a, *aleatoryNumber, module);
            temp = (long double) (*aleatoryNumber) / (long double) maxUInt64;
            if (temp < 0.5) {
                theBit = 0;
            } else {
                theBit = 1;
            }
            *(shiftRegister + index0) |= (theBit << index1);
        }
    }
}

void ShiftVacuum(unsigned long long int *shiftRegister) {
    int address13 = OFFSET_13;
    int address7 = OFFSET_7;
    int address5 = OFFSET_5;
    int address3 = OFFSET_3;
    int address2 = OFFSET_2;
    int addressZero = OFFSET_ZERO;
    unsigned long long int temp0 = 0;
    unsigned long long int temp1 = 0;

    do {

        temp0 = *(shiftRegister + address7) ^ ~(*(shiftRegister + address13));
        temp1 = ~temp0 ^ *(shiftRegister + address5);
        temp0 = temp1 ^ ~(*(shiftRegister + address3));
        temp1 = ~temp0 ^ *(shiftRegister + address2);
        temp0 = temp1 ^ ~(*(shiftRegister + addressZero));

        *(shiftRegister + addressZero) = temp0;

        address13++;
        address7++;
        address5++;
        address3++;
        address2++;
        addressZero++;

    } while (addressZero != SHIFT_LENGTH);
}

void ShiftCollider(
        unsigned long long int *shiftRegister,
        unsigned long long int *shiftRegisterEntropy
        ) {
    int index;
    unsigned long long int aleatoryNumber = 0;
    unsigned long long int *shiftRegisterPlus = NULL;

    shiftRegisterPlus = GetMemorySpace(SHIFT_LENGTH);
    InitShiftRegisterPlus(&aleatoryNumber, shiftRegisterPlus, shiftRegisterEntropy);

    for (index = 0; index < SHIFT_LENGTH; index++) {
        *(shiftRegister + index) = *(shiftRegister + index) ^ ~(*(shiftRegisterPlus + index));
    }

    GiveBackMemorySpace(shiftRegisterPlus);
}

unsigned long long int CallShift(unsigned long long int *shiftRegister) {
    static int address13 = OFFSET_13;
    static int address7 = OFFSET_7;
    static int address5 = OFFSET_5;
    static int address3 = OFFSET_3;
    static int address2 = OFFSET_2;
    static int addressZero = OFFSET_ZERO;
    unsigned long long int temp0 = 0;
    unsigned long long int temp1 = 0;

    temp0 = *(shiftRegister + address7) ^ ~(*(shiftRegister + address13));
    temp1 = ~temp0 ^ *(shiftRegister + address5);
    temp0 = temp1 ^ ~(*(shiftRegister + address3));
    temp1 = ~temp0 ^ *(shiftRegister + address2);
    temp0 = temp1 ^ ~(*(shiftRegister + addressZero));

    *(shiftRegister + addressZero) = temp0;

    address13++;
    address7++;
    address5++;
    address3++;
    address2++;
    addressZero++;

    if (address13 == SHIFT_LENGTH) {
        address13 = 0;
    }
    if (address7 == SHIFT_LENGTH) {
        address7 = 0;
    }
    if (address5 == SHIFT_LENGTH) {
        address5 = 0;
    }
    if (address3 == SHIFT_LENGTH) {
        address3 = 0;
    }
    if (address2 == SHIFT_LENGTH) {
        address2 = 0;
    }
    if (addressZero == SHIFT_LENGTH) {
        addressZero = 0;
    }

    return *(shiftRegister + addressZero);
}

void InitShiftRegisterEntropy(
        unsigned long long int *entropyNumber,
        unsigned long long int *shiftRegisterEntropy
        ) {
    EntropyShiftRegisterOutOfTransientRegime(entropyNumber);

    ShiftInit(entropyNumber, shiftRegisterEntropy);

    ShiftVacuum(shiftRegisterEntropy);
}

void InitShiftRegisterWithCollider(
        unsigned long long int *aleatoryNumber,
        unsigned long long int *shiftRegister,
        unsigned long long int *shiftRegisterEntropy) {
    OutOfTransientRegime(aleatoryNumber, shiftRegisterEntropy);

    ShiftInit(aleatoryNumber, shiftRegister);

    ShiftCollider(shiftRegister, shiftRegisterEntropy);

    ShiftVacuum(shiftRegister);
}

void InitShiftRegisterPlus(unsigned long long int *aleatoryNumber,
        unsigned long long int *shiftRegisterPlus,
        unsigned long long int *shiftRegisterEntropy) {
    OutOfTransientRegime(aleatoryNumber, shiftRegisterEntropy);

    ShiftInit(aleatoryNumber, shiftRegisterPlus);
}

unsigned long long int GetAleatoryULLInt(unsigned long long int *shiftRegister) {
    int index;
    unsigned long long int shiftNumber = 0;
    unsigned long long int shiftVector[OFFSET_2] = {0};

    for (index = 0; index < OFFSET_2; index++) {
        shiftVector[index] = (unsigned long long int) CallShift(shiftRegister);
    }

    shiftNumber = shiftVector[0];

    for (index = 1; index < OFFSET_2; index++) {
        shiftNumber ^= ~(shiftVector[index]);
    }

    return shiftNumber;
}

long double GetAleatoryLDouble(unsigned long long int *shiftRegister) {
    int index;
    unsigned long long int aleatoryNumber = 0;
    unsigned long long int aleatoryVector[OFFSET_3] = {0};
    unsigned long long int maxUInt64 = 0;
    long double aleatoryLDouble;

    maxUInt64 = ~maxUInt64;

    for (index = 0; index < OFFSET_3; index++) {
        aleatoryVector[index] = (unsigned long long int) CallShift(shiftRegister);
    }

    aleatoryNumber = aleatoryVector[0];

    for (index = 1; index < OFFSET_3; index++) {
        aleatoryNumber ^= ~(aleatoryVector[index]);
    }

    aleatoryLDouble = (long double) aleatoryNumber / (long double) maxUInt64;

    return aleatoryLDouble;
}

/* definition function for ae number [0;1]x + [0;1]y */
ae GetAENumber(unsigned long long int *shiftRegister) {
    int index;
    unsigned long long int aleatoryNumberX = 0;
    unsigned long long int xVector[OFFSET_2] = {0};
    unsigned long long int aleatoryNumberY = 0;
    unsigned long long int yVector[OFFSET_3] = {0};
    unsigned long long int maxUInt64 = 0;
    ae aeNumber;

    maxUInt64 = ~maxUInt64;

    /* x side */
    for (index = 0; index < OFFSET_2; index++) {
        xVector[index] = (unsigned long long int) CallShift(shiftRegister);
    }

    aleatoryNumberX = xVector[0];

    for (index = 1; index < OFFSET_2; index++) {
        aleatoryNumberX ^= xVector[index];
    }

    aeNumber.x = (long double) aleatoryNumberX / (long double) maxUInt64;

    /* y side */
    for (index = 0; index < OFFSET_3; index++) {
        yVector[index] = (unsigned long long int) CallShift(shiftRegister);
    }

    aleatoryNumberY = yVector[0];

    for (index = 1; index < OFFSET_3; index++) {
        aleatoryNumberY ^= yVector[index];
    }

    aeNumber.y = (long double) aleatoryNumberY / (long double) maxUInt64;

    /* return aleatory environment number */
    return aeNumber;
}

#endif
