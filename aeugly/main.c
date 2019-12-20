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

#define RESPONSE_NUMBERS_LENGTH 15
#define RESPONSE_PHI_LENGTH 12

int main(int argc, char *argv[]) {
    /* data for shift register entropy */
    unsigned long long int *shiftRegisterEntropy = NULL;
    unsigned long long int entropyNumber = 0;

    /* data for shift register functions section */
    unsigned long long int *shiftRegister = NULL;
    unsigned long long int aleatoryNumber = 0;

    /* variables for chi-square test */
    unsigned int vectorOfPopulates[CATEGORY] = {0};
    unsigned long long int tempPhi = 0;
    long double phi = 0.0;

    /* specific */
    char responseAleatoryNumbers[RESPONSE_NUMBERS_LENGTH] = {'\0'};
    char responsePhi[RESPONSE_PHI_LENGTH] = {'\0'};
    char fileName[LENGTH_MAX] = {'\0'};
    int numberOfSetOfFive = 0;
    int vectorOfAleatoryNumbers[NUMBERS] = {0};
    int vectorOfFrequency[MODALITY] = {0};

    /* ----- */
    const char *programName = NULL;
    int options = 0;
    int lose = 0;

    /* option for this program */
    static const struct option longOptions[] = {
        { "accept-refuse", required_argument, NULL, 'a'},
        { "random-walk", required_argument, NULL, 'r'},
        { "chi-square-test", no_argument, NULL, 'c'},
        { "version", no_argument, NULL, 'v'},
        { "help", no_argument, NULL, 'h'},
        { NULL, 0, NULL, 0}
    };

    programName = argv[0];
    /* ----- */

    /* Initialize shift register entropy */
    shiftRegisterEntropy = GetMemorySpace(SHIFT_LENGTH);
    InitShiftRegisterEntropy(&entropyNumber, shiftRegisterEntropy);

    /* Initialize shift register */
    shiftRegister = GetMemorySpace(SHIFT_LENGTH);
    InitShiftRegisterWithCollider(&aleatoryNumber, shiftRegister, shiftRegisterEntropy);

    while ((options = getopt_long(argc, argv, "a:r:cvh", longOptions, NULL)) != -1) {
        switch (options) {
            case 'c':

                Populate(vectorOfPopulates, shiftRegister);

                ComputeTemporaryPhi(&tempPhi, vectorOfPopulates);
                ComputePhi(&phi, &tempPhi);
                InsertPhi(&phi, responsePhi);

                break;
            case 'v':

                ShowVersion();

                break;
            case 'h':

                ShowHelp(programName);

                break;
            case 'a':

                if (argc > 2) {
                    GetFileName(fileName, argv[2], shiftRegister, shiftRegisterEntropy);

                    GetDataIntegerFromCSVFile(vectorOfFrequency, fileName, shiftRegister, shiftRegisterEntropy);

                    GetNumberOfSetOfFive(&numberOfSetOfFive, vectorOfFrequency, shiftRegister, shiftRegisterEntropy);

                    AcceptRefuse(vectorOfAleatoryNumbers,
                            vectorOfFrequency,
                            &numberOfSetOfFive,
                            shiftRegister,
                            shiftRegisterEntropy);

                    InsertAleatoryNumber(vectorOfAleatoryNumbers, responseAleatoryNumbers);

                } else {
                    puts("For example: aeugly --accept-refuse data.csv or: aeugly -a data.csv");

                    /* Give back memory space allocated for shift registers */
                    GiveBackMemorySpace(shiftRegisterEntropy);
                    GiveBackMemorySpace(shiftRegister);

                    exit(EXIT_FAILURE);
                }
                break;
            case 'r':

                if (argc > 2) {
                    GetFileName(fileName, argv[2], shiftRegister, shiftRegisterEntropy);

                    GetDataIntegerFromCSVFile(vectorOfFrequency, fileName, shiftRegister, shiftRegisterEntropy);

                    GetNumberOfSetOfFive(&numberOfSetOfFive, vectorOfFrequency, shiftRegister, shiftRegisterEntropy);

                    RandomWalk(vectorOfAleatoryNumbers,
                            vectorOfFrequency,
                            &numberOfSetOfFive,
                            shiftRegister,
                            shiftRegisterEntropy);

                    InsertAleatoryNumber(vectorOfAleatoryNumbers, responseAleatoryNumbers);

                } else {
                    puts("For example: aeugly --random-walk data.csv or: aeugly -r data.csv");

                    /* Give back memory space allocated for shift registers */
                    GiveBackMemorySpace(shiftRegisterEntropy);
                    GiveBackMemorySpace(shiftRegister);

                    exit(EXIT_FAILURE);
                }
            default:
                lose = 1;
                break;
        }
    }

    if (lose || optind < argc) {
        if (optind < argc) {
            fprintf(stderr, "%s: extra operand: %s\n", programName, argv[optind]);
            fprintf(stderr, "Try \' %s --help \' for more information.\n", programName);

            /* Give back memory space allocated for shift registers */
            GiveBackMemorySpace(shiftRegisterEntropy);
            GiveBackMemorySpace(shiftRegister);

            exit(EXIT_FAILURE);
        }
    }

    /* Give back memory space allocated for shift registers */
    GiveBackMemorySpace(shiftRegisterEntropy);
    GiveBackMemorySpace(shiftRegister);

    ShowResponse(responseAleatoryNumbers, responsePhi);

    exit(EXIT_SUCCESS);
}
