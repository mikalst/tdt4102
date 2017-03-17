//
//  utilities.cpp
//  oving4
//
//  Created by Mikal Stapnes on 29/01/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#include "utilities.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimes2(int* startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        *startValue = *startValue + increment;
    }
}

void swapNumbers(int* number1,int* number2) {
    /* Ja, for at denne funksjonen skal være effektiv er det best å bruke pekere. Ellers vil en måtte returnere en array med tall og det vil bruke opp unødvendig minne */
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

void randomizeArray(int* startOfArray, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        *(startOfArray + i) = rand()%100;
    }
}

void sortArray(int* myTable, int size) {
    for (int i=0; i<(size-1); i++) {
        for (int j=(i+1); j<size; j++) {
            if( *(myTable + i) > *(myTable + j) ) {
                swapNumbers((myTable + i), (myTable + j));
            }
        }
    }
}

double medianOfArray(int* startOfArray, int size) {
    /* Får jo selvfølgelig annerledes svar ettersom median på en usortert liste ikke er median i det hele tatt */
    
    double varMedian;
    if (size%2) {
        varMedian = double((*(startOfArray+size/2)+*(startOfArray+size/2 + 1))/2);
    }
    else {
        varMedian = double(*(startOfArray + size/2));
    }
    return varMedian;
}

void randomizeCStrings(char* startOfArray, int size, char upperBoundary, char lowerBoundary) {
    srand(time(NULL));
    for (int i=0; i<size; i++) {
        *(startOfArray + i) = rand()%(lowerBoundary-upperBoundary+1) + upperBoundary;
    }
}

void readInputToCString(char *varCString, int size, char upperBoundary, char lowerBoundary) {
    std::cout << "Skriv inn " << size << " bokstaver mellom " << upperBoundary << " og " << lowerBoundary << std::endl;
    for (int i=0; i<size; i++) {
        char inChar;
        bool validInput = false;
        while (validInput == false) {
            std::cin >> inChar;
            if (toupper(inChar) >= upperBoundary and toupper(inChar) <= lowerBoundary) {
                validInput = true;
            }
            else {
                std::cout << "Ugyldig karakter, prøv på nytt!" << std::endl;
            }
        }
        *(varCString + i) = toupper(inChar);
    }
}

int checkCharactersAndPosition(char* code, char* guess, int size) {
    int correct = 0;
    for (int i=0; i<size; i++) {
        if (*(code + i) == *(guess + i)) {
            correct++;
        }
    }
    return correct;
}

int checkCharacters(char* code, char* guess, int size, int letters) {
    int sum = 0;
    for (int x=65; x<(65+letters); x++) {
        int occurencesCode= countOccurencesOfCharacter(code, size, x);
        int occurencesGuess = countOccurencesOfCharacter(guess, size, x);
        sum += std::min(occurencesCode, occurencesGuess);
    }
    return sum;
}

int countOccurencesOfCharacter(char myCString[], int size, char character) {
    int occurences = 0;
    for (int i=0; i<size; i++) {
        if ((myCString[i])==character) {
            occurences++;
        }
    }
    return occurences;
}
