//
//  blackjack.hpp
//  oving_5
//
//  Created by Mikal Stapnes on 12/02/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#ifndef blackjack_hpp
#define blackjack_hpp

#include <stdio.h>
#include "card.hpp"

class Blackjack {
public:
    void playGame();
    void drawInitialCards();
    bool askPlayerDrawCard();
    int getCardValue(Card* card);
    int getDealerCardValue(Card* card, int dealerValue);
    int getPlayerCardValue(Card* card);
private:
    CardDeck deck;
    int playerHand;
    int dealerHand;
    int playerCardsDrawn;
    int dealerCardsDrawn;
};

#endif /* blackjack_hpp */
