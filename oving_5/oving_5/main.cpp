//
//  main.cpp
//  oving_5
//
//  Created by Mikal Stapnes on 10/02/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#include <iostream>
#include "card.hpp"
#include "blackjack.hpp"

int main(int argc, const char * argv[]) {
    
    bool playAgain = true;
    
    
    while(playAgain) {
        Blackjack blackjack;
        blackjack.playGame();
        std::cout << "Ønsker du å spille mer? ";
        char response[10];
        std::cin >> response;
        if (toupper(response[0])=='J') {
            continue;
        }
        else {
            playAgain = false;
        }
    }
    
    return 0;
}
