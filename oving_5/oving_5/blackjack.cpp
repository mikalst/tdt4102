//
//  blackjack.cpp
//  oving_5
//
//  Created by Mikal Stapnes on 12/02/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#include "blackjack.hpp"
#include "card.hpp"
#include <iostream>
#include <string>
#include <cctype>


int Blackjack::getCardValue(Card* card) {
    Card activeCard = *card;
    Rank activeRank = activeCard.getRank();
    int value = static_cast<int>(activeRank);
    if (value < 11) {
        return value;
    }
    else if (value < 14) {
        return 10;
    }
    else {
        return -1;
    }
}

int Blackjack::getPlayerCardValue(Card* card) {
    int value = Blackjack::getCardValue(card);
    int end_value;
    if (value == -1) {
        do {
            std::cout << "Skal esset være 1 eller 11? ";
            std::cin >> end_value;
        } while (not(end_value == 1 or end_value == 11));
    }
    else {
        return value;
    }
    return end_value;
}

int Blackjack::getDealerCardValue(Card* card, int dealerValue) {
    int value = Blackjack::getCardValue(card);
    if (value == -1 and (dealerValue + 11) > 21) {
        return (dealerValue+1);
    }
    else if (value == -1) {
        return (dealerValue+11);
    }
    else {
        return (dealerValue+value);
    }
}

bool Blackjack::askPlayerDrawCard() {
    std::cout << "Ønsker du å trekke et nytt kort? ";
    char response[10];
    std::cin >> response;
    if (toupper(response[0])=='J') {
        return true;
    }
    return false;
}

void Blackjack::drawInitialCards() {
    Card hand_card_1 = deck.drawCard();
    Card hand_card_2 = deck.drawCard();
    std::cout << "Dine to første kort: " << hand_card_1.toStringShort() << " og " << hand_card_2.toStringShort() << std::endl;
    Card* pointer_hand_card_1 = &hand_card_1;
    Card* pointer_hand_card_2 = &hand_card_2;
    Card dealer_card_1 = deck.drawCard();
    std::cout << "Dealerens første kort: " << dealer_card_1.toStringShort() << std::endl;
    Card dealer_card_2 = deck.drawCard();
    Card* pointer_dealer_card_1 = &dealer_card_1;
    Card* pointer_dealer_card_2 = &dealer_card_2;
    playerHand += getPlayerCardValue(pointer_hand_card_1) + getPlayerCardValue(pointer_hand_card_2);
    dealerHand += getDealerCardValue(pointer_dealer_card_1, dealerHand) + getDealerCardValue(pointer_dealer_card_2, dealerHand);
}

void Blackjack::playGame() {
    playerHand = 0;
    dealerHand = 0;
    deck.shuffle();
    drawInitialCards();
    bool get_new_card = true;
    while (get_new_card) {
        get_new_card = askPlayerDrawCard();
        if (get_new_card == false) {
            break;
        }
        Card additional = deck.drawCard();
        std::cout << additional.toStringShort() << std::endl;
        Card* pointer = &additional;
        playerHand += getPlayerCardValue(pointer);
    }
    while (dealerHand < 17) {
        Card additional = deck.drawCard();
        Card* pointer = &additional;
        dealerHand += getPlayerCardValue(pointer);
    }
    std::cout << "Du fikk " << playerHand << " og dealeren fikk " << dealerHand << std::endl;
    if (playerHand > 21) {
        std::cout << "Du tapte fordi du fikk mer enn 21" << std::endl;
    }
    else if (dealerHand > 21) {
        std::cout << "Du vant!!!" << std::endl;
    }
    else if (playerHand < dealerHand) {
        std::cout << "Du tapte fordi dealeren fikk en bedre hånd enn deg" << std::endl;
    }
    else {
        std::cout << "Du vant!!!" << std::endl;
    }
}
