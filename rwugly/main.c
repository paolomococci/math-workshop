/*
 * main.c
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

#include "system.h"

int main(int argc, char *argv[]) {
    const char *programName;
    static const struct option longOptions[] = {
        { "bind", required_argument, NULL, 'b'},
        { "test", no_argument, NULL, 't'},
        { "version", no_argument, NULL, 'v'},
        { "help", no_argument, NULL, 'h'},
        { NULL, 0, NULL, 0}
    };

    int options;
    int lose = 0;

    /* data for shift register functions section */
    unsigned long long int *shiftRegister = NULL;
    unsigned long long int aleatoryNumber = 0;

    /* variables for chi-square test */
    unsigned int vectorOfPopulates[CATEGORY] = {0};
    unsigned long long int tempPhi = 0;
    long double phi = 0.0;

    /* specific */
    char fileName[LENGTH_MAX] = {'\0'};
    int numberOfSetOfFive = 0;
    int vectorOfAleatoryNumbers[NUMBERS] = {0};
    int vectorOfFrequency[MODALITY] = {0};

    programName = argv[0];

    /* Initialize shift register */
    shiftRegister = GetMemorySpace(SHIFT_LENGTH);
    InitShiftRegisterWithCollider(&aleatoryNumber, shiftRegister);

    while ((options = getopt_long(argc, argv, "b:tvh", longOptions, NULL)) != -1) {
        switch (options) {
            case 't':

                Populate(vectorOfPopulates, shiftRegister);

                ComputeTemporaryPhi(&tempPhi, vectorOfPopulates);
                ComputePhi(&phi, &tempPhi);
                ShowPhi(&phi);

                break;
            case 'v':

                ShowVersion();

                break;
            case 'h':

                ShowHelp(programName);

                break;
            case 'b':

                if (argc > 2) {
                    GetFileName(fileName, argv[2], shiftRegister);

                    GetDataIntegerFromCSVFile(vectorOfFrequency, fileName, shiftRegister);

                    GetNumberOfSetOfFive(&numberOfSetOfFive, vectorOfFrequency, shiftRegister);

                    BindHyperGeometricalDistribution(vectorOfAleatoryNumbers,
                            vectorOfFrequency,
                            &numberOfSetOfFive,
                            shiftRegister);

                    ShowAleatoryNumbers(vectorOfAleatoryNumbers);

                } else {
                    puts("For example: rwugly --bind datafile.csv or: rwugly -b datafile.csv");

                    /* Give back memory space allocated for shift register */
                    GiveBackMemorySpace(shiftRegister);

                    exit(EXIT_FAILURE);
                }
                break;
            default:
                lose = 1;
                break;
        }
    }

    if (lose || optind < argc) {
        if (optind < argc) {
            fprintf(stderr, "%s: extra operand: %s\n", programName, argv[optind]);
            fprintf(stderr, "Try \' %s --help \' for more information.\n", programName);

            /* Give back memory space allocated for shift register */
            GiveBackMemorySpace(shiftRegister);

            exit(EXIT_FAILURE);
        }
    }

    /* Give back memory space allocated for shift register */
    GiveBackMemorySpace(shiftRegister);

    exit(EXIT_SUCCESS);
}
