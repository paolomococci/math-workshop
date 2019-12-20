/*
 * lib.h
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

/* define section */
#ifndef LIB_H
#define LIB_H

#define NUMBERS 5
#define MODALITY 90
#define M 1.0
#define RESCUE 1000000

/* extern functions */
extern unsigned long long int GetAleatoryULLInt(unsigned long long int *);
extern long double GetAleatoryLDouble(unsigned long long int *);

/* prototype of basic functions section */
void ShowVersion(void);
void ShowHelp(const char *);
unsigned long long int * GetMemorySpace(int);
void GiveBackMemorySpace(unsigned long long int *);
void Riddle(int *, int *);
void GetNumberOfSetOfFive(int *, int *, unsigned long long int *, unsigned long long int *);
int GetAleatoryBindNumber(double *, unsigned long long int *, unsigned long long int *);
void AcceptRefuse(int *, int *, int *, unsigned long long int *, unsigned long long int *);
void ShowAleatoryNumbers(int *);
void InsertAleatoryNumber(int *, char *);
void ShowResponse(char *, char *);

/* definition of functions section */
void ShowVersion(void) {
    puts("aeugly version 0.2");
}

void ShowHelp(const char *programName) {
    printf("%s --version : print version and exit \n", programName);
    printf("%s --help : print this help and exit \n", programName);
    printf("%s --accept-refuse data.csv : accept-refuse method for bind to experimental data distribution \n", programName);
    printf("%s --random-walk data.csv : random-walk method for bind to experimental data distribution \n", programName);
    printf("%s --chi-square-test : chi-square test of shift register \n", programName);
}

unsigned long long int * GetMemorySpace(int length) {
    size_t sizeInBitOfMemorySpace = 0;
    unsigned long long int *pointerToMemorySpace = NULL;

    sizeInBitOfMemorySpace = ((sizeof (unsigned long long int) * 8) * length);

    pointerToMemorySpace = (unsigned long long int *) malloc(sizeInBitOfMemorySpace);

    if (pointerToMemorySpace == NULL) {
        puts("Error: memory exhausted!");
        exit(EXIT_FAILURE);
    }

    memset(pointerToMemorySpace, 0, sizeInBitOfMemorySpace);

    return pointerToMemorySpace;
}

void GiveBackMemorySpace(unsigned long long int *pointerToMemorySpace) {
    free(pointerToMemorySpace);
}

void Riddle(int *i, int *vectorOfAleatoryNumbers) {
    if (*i) {
        if (*i == 1) {
            if (*(vectorOfAleatoryNumbers + 1) == *vectorOfAleatoryNumbers) {
                *i -= 1;
            }
        } else if (*i == 2) {
            if (*(vectorOfAleatoryNumbers + 2) == *vectorOfAleatoryNumbers ||
                    *(vectorOfAleatoryNumbers + 2) == *(vectorOfAleatoryNumbers + 1)) {
                *i -= 1;
            }
        } else if (*i == 3) {
            if (*(vectorOfAleatoryNumbers + 3) == *vectorOfAleatoryNumbers ||
                    *(vectorOfAleatoryNumbers + 3) == *(vectorOfAleatoryNumbers + 1) ||
                    *(vectorOfAleatoryNumbers + 3) == *(vectorOfAleatoryNumbers + 2)) {
                *i -= 1;
            }
        } else if (*i == 4) {
            if (*(vectorOfAleatoryNumbers + 4) == *vectorOfAleatoryNumbers ||
                    *(vectorOfAleatoryNumbers + 4) == *(vectorOfAleatoryNumbers + 1) ||
                    *(vectorOfAleatoryNumbers + 4) == *(vectorOfAleatoryNumbers + 2) ||
                    *(vectorOfAleatoryNumbers + 4) == *(vectorOfAleatoryNumbers + 3)) {
                *i -= 1;
            }
        }
    }
}

void GetNumberOfSetOfFive(int *numberOfSetOfFive,
        int *vectorOfFrequency,
        unsigned long long int *shiftRegister,
        unsigned long long int *shiftRegisterEntropy) {
    int i;

    /* determine value of number of set of five */
    for (i = 0; i < MODALITY; i++) {
        *(numberOfSetOfFive) += *(vectorOfFrequency + i);
    }

    if (!(*(numberOfSetOfFive)) || (*(numberOfSetOfFive) % NUMBERS)) {
        puts("Error: invalid number of set of five.");

        /* Give back memory space allocated for shift registers */
        GiveBackMemorySpace(shiftRegisterEntropy);
        GiveBackMemorySpace(shiftRegister);

        exit(EXIT_FAILURE);
    }

    *(numberOfSetOfFive) /= NUMBERS;
}

int GetAleatoryBindNumber(double *vectorOfFrequencyNormalized,
        unsigned long long int *shiftRegister,
        unsigned long long int *shiftRegisterEntropy) {
    int aleatoryBindNumber;
    int control = 1;
    int rescue = 0;
    double u2;
    double m;

    do {
        rescue++;

        if (rescue > RESCUE) {
            puts("Error: out of time");
            puts("You sure have sufficien sperimental data?");

            /* Give back memory space allocated for shift registers */
            GiveBackMemorySpace(shiftRegisterEntropy);
            GiveBackMemorySpace(shiftRegister);

            exit(EXIT_FAILURE);
        }

        aleatoryBindNumber = (int) (GetAleatoryULLInt(shiftRegister) % 91);
        u2 = GetAleatoryLDouble(shiftRegister);

        m = u2 * M;

        if (m <= *(vectorOfFrequencyNormalized + aleatoryBindNumber)) {
            control = 0;
        }

    } while (control);

    return aleatoryBindNumber;
}

void AcceptRefuse(int *vectorOfAleatoryNumbers,
        int *vectorOfFrequency,
        int *numberOfSetOfFive,
        unsigned long long int *shiftRegister,
        unsigned long long int *shiftRegisterEntropy) {
    int i;
    double vectorOfFrequencyNormalized[MODALITY] = {0.0};

    for (i = 0; i < MODALITY; i++) {
        *(vectorOfFrequencyNormalized + i) = (double) *(vectorOfFrequency + i) / (double) *numberOfSetOfFive;
    }

    for (i = 0; i < NUMBERS; i++) {

        *(vectorOfAleatoryNumbers + i) = GetAleatoryBindNumber(vectorOfFrequencyNormalized, shiftRegister, shiftRegisterEntropy);

        Riddle(&i, vectorOfAleatoryNumbers);
    }
}

void ShowAleatoryNumbers(int *vectorOfAleatoryNumbers) {
    printf("%d,%d,%d,%d,%d",
            ++(*(vectorOfAleatoryNumbers)),
            ++(*(vectorOfAleatoryNumbers + 1)),
            ++(*(vectorOfAleatoryNumbers + 2)),
            ++(*(vectorOfAleatoryNumbers + 3)),
            ++(*(vectorOfAleatoryNumbers + 4)));
}

void InsertAleatoryNumber(int *vectorOfAleatoryNumbers, char *response) {
    snprintf(
            response,
            14,
            "%d,%d,%d,%d,%d",
            ++(*(vectorOfAleatoryNumbers)),
            ++(*(vectorOfAleatoryNumbers + 1)),
            ++(*(vectorOfAleatoryNumbers + 2)),
            ++(*(vectorOfAleatoryNumbers + 3)),
            ++(*(vectorOfAleatoryNumbers + 4))
            );
}

void ShowResponse(char *numbers, char *phi) {
    int ifNumbers = 0;
    int ifPhi = 0;

    ifNumbers = strnlen(numbers, 15);
    ifPhi = strnlen(phi, 12);

    if (ifNumbers && ifPhi) {
        printf("%s,%s\n", numbers, phi);
    } else if (ifNumbers) {
        printf("%s\n", numbers);
    } else if (ifPhi) {
        printf("%s\n", phi);
    }
}

#endif
