//
//  main.cpp
//  oving4
//
//  Created by Mikal Stapnes on 29/01/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#include <iostream>
#include "utilities.hpp"
#include "tests.hpp"
#include "mastermind.hpp"

int main(int argc, const char * argv[]) {
    /*
    std::cout << "Velkommen til Mikal sitt program, her er menyen: \n" ;
    while (true) {
        std::cout  << " 0) Avslutt \n"
                    << " 1) testCallByValue() \n"
                    << " 2) testCallByRef() \n"
        << std::endl ;
        int n = 0;
        std::cin >> n;
        switch (n) {
            case 0 : std::cout << "Ha det bra!" << std::endl;
                return 0;
            case 1 : testCallByValue();
                break;
            case 2 : testCallByRef();
                break;
            default : std::cout << "Vennligst velg et tall" ;
        }
        std::cout << std::endl;
    testTablesSorting();
    testCStrings();
    return 0;
    */
    playMastermind();
}
