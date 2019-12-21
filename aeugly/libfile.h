/*
 * libfile.h
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

/* define section */
#ifndef LIBFILE_H
#define LIBFILE_H

#define LENGTH_MAX 1024

/* extern function */
void GiveBackMemorySpace(unsigned long long int *);

/* prototype of functions section */
void GetFileName(char *, char *, unsigned long long int *, unsigned long long int *);
void GetDataIntegerFromCSVFile(int *, char *, unsigned long long int *, unsigned long long int *);

/* definition of functions section */
void GetFileName(char *fileName,
        char *argStr,
        unsigned long long int *shiftRegister,
        unsigned long long int *shiftRegisterEntropy) {
    size_t numberOfSize = 0;

    if (isalpha(*(argStr))) {

        numberOfSize = strlen(argStr);

        if (numberOfSize < (LENGTH_MAX - 1)) {
            strncpy(fileName, argStr, numberOfSize);
        } else {

            /* Give back memory space allocated for shift registers */
            GiveBackMemorySpace(shiftRegisterEntropy);
            GiveBackMemorySpace(shiftRegister);

            exit(EXIT_FAILURE);
        }
    } else {

        /* Give back memory space allocated for shift registers */
        GiveBackMemorySpace(shiftRegisterEntropy);
        GiveBackMemorySpace(shiftRegister);

        puts("Error: required file in this directory.");
        exit(EXIT_FAILURE);
    }
}

void GetDataIntegerFromCSVFile(int *vectorOfFrequency,
        char *fileName,
        unsigned long long int *shiftRegister,
        unsigned long long int *shiftRegisterEntropy) {
    int i;
    int j;
    int index[NUMBERS];
    FILE *filePointer;

    /* open file */
    filePointer = fopen(fileName, "r");

    if (!(filePointer == NULL)) {

        /* read data and increment frequency vector  */
        do {
            if ((fscanf(filePointer, "%d,%d,%d,%d,%d\n",
                    &(index[0]),
                    &(index[1]),
                    &(index[2]),
                    &(index[3]),
                    &(index[4]))) != 5) {
                puts("Error: content of CSV file required, for example:\n12,34,9,56,81");
                fclose(filePointer);

                /* Give back memory space allocated for shift registers */
                GiveBackMemorySpace(shiftRegisterEntropy);
                GiveBackMemorySpace(shiftRegister);

                exit(EXIT_FAILURE);
            }

            for (i = 0; i < NUMBERS; i++) {
                for (j = 0; j < NUMBERS; j++) {
                    if (i != j) {
                        if (index[i] == index[j]) {
                            puts("Error: two value are equal.");
                            fclose(filePointer);

                            /* Give back memory space allocated for shift registers */
                            GiveBackMemorySpace(shiftRegisterEntropy);
                            GiveBackMemorySpace(shiftRegister);

                            exit(EXIT_FAILURE);
                        }
                    }
                }
            }

            for (i = 0; i < NUMBERS; i++) {
                (*(vectorOfFrequency + (index[i] - 1)))++;
            }

        } while (!feof(filePointer));

        /* close file */
        fclose(filePointer);

    } else {
        puts("Error: invalid file name.");
        fclose(filePointer);

        /* Give back memory space allocated for shift registers */
        GiveBackMemorySpace(shiftRegisterEntropy);
        GiveBackMemorySpace(shiftRegister);

        exit(EXIT_FAILURE);
    }
}

#endif
