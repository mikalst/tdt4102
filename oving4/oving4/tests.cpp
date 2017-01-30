//
//  tests.cpp
//  oving4
//
//  Created by Mikal Stapnes on 29/01/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#include "tests.hpp"
#include "utilities.hpp"
#include <iostream>
#include <cmath>

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    std::cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << std::endl;
}

void testCallByRef() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int* pointerv0 = &v0;
    incrementByValueNumTimes2(pointerv0, increment, iterations);
    std::cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << *pointerv0 << std::endl;
}

void printArray(int* startOfArray, int size) {
    std:: cout << "\n Start --> ";
    for (int i = 0; i < size; i++) {
        std::cout << "[" << *(startOfArray + i) << "]," ;
    }
    std::cout << std::endl;
}

void printArray(char* startOfArray, int size) {
    std:: cout << "\n Start --> ";
    for (int i = 0; i < size; i++) {
        std::cout << "[" << *(startOfArray + i) << "]," ;
    }
    std::cout << std::endl;
}

void testTablesSorting() {
    int percentages[20];
    int* myPointer = percentages;
    printArray(percentages, 20);
    randomizeArray(myPointer, 20);
    printArray(percentages, 20);
    swapNumbers(&percentages[0], &percentages[1]);
    printArray(percentages, 20);
    std::cout << "Median: " << medianOfArray(percentages, 20) <<"\n";
    sortArray(percentages, 20);
    printArray(percentages, 20);
    std::cout << "Median: " << medianOfArray(percentages, 20)<<"\n";
}

void testCStrings() {
    std::cout << std::endl;
    char grades[41] = {};
    randomizeCStrings(grades, 40, 'A', 'E');
    std::cout << grades << std::endl;
    char possibleGrades[7] = {'A','B','C','D','E','F'};
    int gradeCount[6] = {0,0,0,0,0,0};
    for (int i=0; i<6; i++) {
        gradeCount[i] = countOccurencesOfCharacter(grades, 40, possibleGrades[i]);
    }
    //readInputToCString(grades, 8, 'A', 'F');
    printArray(gradeCount, 6);
    int sum = 0;
    for (int i=0; i<6; i++) {
        sum += gradeCount[i] * ((int)possibleGrades[i]-65);
    }
    double average = (6-double(sum)/40);
    std::cout << "Snitt: " << static_cast<char>('A' + round(average) - 1)<< std::endl;
}
