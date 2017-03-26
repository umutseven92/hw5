//
// Created by umut on 13.03.2017.
//

#include "card.h"

Card::Card(Suit s, Rank r) {
    suit = s;
    rank = r;
}

Card::Rank Card::GetRank() const{
    return rank;
}

Card::Suit Card::GetSuit() const{
    return suit;
}

void Card::SetRank(Rank r)
{
    rank = r;
};

void Card::SetSuit(Suit s)
{
    suit = s;
};

ostream &operator<<(ostream &out, Card &card) {
    out << RANK_BY_INDEX[card.GetRank()] << " of " << SUIT_BY_INDEX[card.GetSuit()] << endl;
    return out;
}
