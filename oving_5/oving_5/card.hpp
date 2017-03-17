//
//  card.hpp
//  oving_5
//
//  Created by Mikal Stapnes on 12/02/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#ifndef card_hpp
#define card_hpp

#include <stdio.h>
#include <string>
#include <vector>

enum Suit {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

enum Rank {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

std::string suitToString(Suit suit);

std::string rankToString(Rank rank);

std::string toString(Suit s, Rank r);

std::string toStringShort(Suit s, Rank r);

class Card {
public:
    Card();
    Card(Suit suit, Rank rank);
    void initialize(Suit suit, Rank rank);
    Suit getSuit();
    Rank getRank();
    std::string toString();
    std::string toStringShort();
private:
    Suit s;
    Rank r;
    bool invalid;
};

class CardDeck {
public:
    CardDeck();
    void shuffle();
    Card drawCard();
private:
    std::vector<Card>cards;
    int currentCardIndex;
    void swap(int index_1, int index_2);
    void print();
    void printShort();
};

#endif /* card_hpp */
