//
//  card.cpp
//  oving_5
//
//  Created by Mikal Stapnes on 12/02/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#include "card.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>


// Hvor skal type enums egentlig plasseres, header eller implementation?

std::string suitToString(Suit suit) {
    switch (suit) {
        case 0:
            return "Clubs";
            break;
        case 1:
            return "Diamonds";
            break;
        case 2:
            return "Hearts";
            break;
        case 3:
            return "Spades";
            break;
        default:
            return "ERROR";
            break;
    }
}

std::string rankToString(Rank rank) {
    switch (rank) {
        case 2:
            return "Two";
            break;
        case 3:
            return "Three";
            break;
        case 4:
            return "Four";
            break;
        case 5:
            return "Five";
            break;
        case 6:
            return "Six";
            break;
        case 7:
            return "Seven";
            break;
        case 8:
            return "Eight";
            break;
        case 9:
            return "Nine";
            break;
        case 10:
            return "Ten";
            break;
        case 11:
            return "Jack";
            break;
        case 12:
            return "Queen";
            break;
        case 13:
            return "King";
            break;
        case 14:
            return "Ace";
            break;
        default:
            return "ERROR";
            break;
    }
}

std::string toString(Suit s, Rank r) {
    std::string cardName = rankToString(r) + " of " + suitToString(s);
    return cardName;
}

std::string toStringShort(Suit s, Rank r) {
    std::string suitLetter = suitToString(s).substr(0,1);
    std::string rankNumber  = std::to_string(static_cast<int>(r));
    return suitLetter + rankNumber;
}

Card::Card() {
    invalid = true;
}

Card::Card(Suit suit, Rank rank) {
    s = suit;
    r = rank;
    invalid = false;
}

void Card::initialize(Suit suit, Rank rank) {
    s = suit;
    r = rank;
    invalid = false;
}

Suit Card::getSuit() {
    return s;
}

Rank Card::getRank() {
    return r;
}

std::string Card::toString() {
    return ::toString(s, r);
}

std::string Card::toStringShort() {
    return ::toStringShort(s, r);
}

CardDeck::CardDeck() {
    for (int x = TWO; x <= ACE; x++) {
        for (int y = CLUBS; y <= SPADES; y++) {
            Suit suit = static_cast<Suit>(y);
            Rank rank = static_cast<Rank>(x);
            cards.push_back(Card(suit, rank));
        }
    }
}

void CardDeck::swap(int index_1, int index_2) {
    Card temp1 = cards.at(index_1);
    Card temp2 = cards.at(index_2);
    cards.at(index_2) = temp1;
    cards.at(index_1) = temp2;
}

void CardDeck::print() {
    for (int index = 0; index < 52; index++) {
        std::cout << cards.at(index).toString() << std::endl;
    }
}

void CardDeck::printShort() {
    for (int index = 0; index < 52; index++) {
        std::cout << cards.at(index).toStringShort() << std::endl;
    }
}

// Feilen ligger her et sted
void CardDeck::shuffle() {
    srand(std::time(nullptr));
    for (int x = 0; x < 100; x++) {
        int index_1 = rand()%52;
        int index_2 = rand()%52;
        CardDeck::swap(index_1, index_2);
    }
}

Card CardDeck::drawCard() {
    Card upperCard = cards.back();
    cards.pop_back();
    return upperCard;
}

