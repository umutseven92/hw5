//
// Created by umut on 13.03.2017.
//

#ifndef CARDS_DECK_H
#define CARDS_DECK_H

#include "card.h"

const int CARD_COUNT = 52;

class Deck {
private:

    Card *cards;

    void Shuffle();

public:
    Deck();

    Card *GetCards();

    Card *Deal();
};

ostream &operator<<(ostream &out, Deck &deck);

#endif //CARDS_DECK_H
