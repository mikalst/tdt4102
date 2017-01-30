//
//  utilities.hpp
//  oving4
//
//  Created by Mikal Stapnes on 29/01/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#ifndef utilities_hpp
#define utilities_hpp

#include <stdio.h>

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

void incrementByValueNumTimes2(int* startValue, int increment, int numTimes);

void swapNumbers(int* number1,int* number2);

void randomizeArray(int* startOfArray, int size);

void sortArray(int* myTable, int size);

double medianOfArray(int* startOfArray, int size);

void randomizeCStrings(char* startOfArray, int size, char upperBoundary, char lowerBoundary);

void readInputToCString(char *varCString, int size, char upperBoundary, char lowerBoundary);

int countOccurencesOfCharacter(char myCString[], int size, char character);

int checkCharactersAndPosition(char* code, char* guess, int size);

int checkCharacters(char* code, char* guess, int size, int letters);

#endif /* utilities_hpp */

