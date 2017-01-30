//
//  mastermind.cpp
//  oving4
//
//  Created by Mikal Stapnes on 30/01/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#include "mastermind.hpp"
#include "utilities.hpp"
#include <iostream>

int playMastermind() {
    int const SIZE = 4;
    int const LETTERS = 6;
    
    int attempts = 10;
    bool gameWin = false;
    
    char code[SIZE];
    char guess[SIZE];
    
    randomizeCStrings(code, 4, 'A', 'A'+(LETTERS-1));
    std::cout << "<--- Mastermind --->\n\n\n" << std::endl;
    //std::cout << code;
    
    while (attempts > 0) {
        std::cout << "Du har " << attempts << " forsøk på å gjette koden!\n\n";
        readInputToCString(guess, 4, 'A', 'A'+(LETTERS-1));
        int correctCompletely = checkCharactersAndPosition(code, guess, SIZE);
        int correctCharacter = checkCharacters(code, guess, SIZE, LETTERS) - correctCompletely;
        
        std::cout << "Du gjettet " << correctCompletely << " fullstendig riktig og " << correctCharacter << " kun med riktig bokstav " << std::endl;
        attempts--;
        if (correctCompletely==4) {
            gameWin = true;
            break;
        }
    }
    if (gameWin) {
        std::cout << "Congratulations, you won! " << std::endl;
    }
    else {
        std::cout << "You lose! " << std::endl;
    }
    return 0;
    
}
