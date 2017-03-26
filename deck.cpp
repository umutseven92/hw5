//
// Created by umut on 13.03.2017.
//

#include "deck.h"
#include <stdlib.h>

void Deck::Shuffle() {

    // Do the Knuth shuffle
    for (int i = CARD_COUNT - 1; i > 0; --i) {
        int r = rand() % CARD_COUNT;
        Card temp = this->cards[i];
        this->cards[i] = this->cards[r];
        this->cards[r] = temp;
    }
}

Deck::Deck() {
    cards = new Card[CARD_COUNT];

    // Generate deck here
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < CARD_COUNT / 4; ++i) {
            Card::Suit s = static_cast<Card::Suit>(j); // Cast int value to enum
            Card::Rank r = static_cast<Card::Rank>(i);

            cards[13 * j + i] = Card(s, r);
        }
    }

    // Then shuffle them
    this->Shuffle();
}

Card *Deck::GetCards() {
    return cards;
}

Card *Deck::Deal() {
    int r = rand() % CARD_COUNT;
    return &(cards[r]);
}

ostream &operator<<(ostream &out, Deck &deck) {
    Card *cards = deck.GetCards();

    for (int i = 0; i < CARD_COUNT; ++i) {
        cout << cards[i];
    }
    return out;
}
