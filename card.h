//
// Created by umut on 13.03.2017.
//

#ifndef CARDS_CARD_H
#define CARDS_CARD_H

#include <iostream>
#include <string>

using namespace std;

const string SUIT_BY_INDEX[4] = {"Hearts", "Spades", "Diamonds", "Clubs"};
const string RANK_BY_INDEX[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack",
                                  "Queen", "King"};

class Card {

public:
    enum Suit {
        Hearts,
        Spades,
        Diamonds,
        Clubs
    };

    enum Rank {
        Ace,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King
    };

    Card() {}

    Card(Suit s, Rank r);

    Rank GetRank() const;

    Suit GetSuit() const;

    void SetRank(Rank r);

    void SetSuit(Suit s);

private:
    Suit suit;
    Rank rank;

};

ostream &operator<<(ostream &out, Card &card);

#endif //CARDS_CARD_H
