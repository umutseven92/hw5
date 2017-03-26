//
// Created by umut on 19.03.2017.
//

#include <iostream>
#include <vector>
#include "card.h"
#include "deck.h"

using namespace std;

int main() {

    const int PILE_COUNT = 13;
    const int PILE_CARD_COUNT = 4;

    Deck d;
    Card *dCards = d.GetCards();

    vector<vector<Card>> cVect;
    cVect.resize(PILE_COUNT);

    // cVect[0] is the centre pile, 1-12 are the surrounding piles, clockwise starting from the top
    for (int i = 0; i < PILE_COUNT; i++) {
        for (int j = 0; j < PILE_CARD_COUNT; j++) {
            int ind = (i*PILE_CARD_COUNT) + j;
            cVect[i].push_back(dCards[ind]);
        }
    }

    int kingCount = 0;
    int revealedCount = 0;
    int startDeck = 0;

    while(true)
    {
        Card c = cVect[startDeck].back(); //Get the top card
        cVect[startDeck].pop_back(); // Remove the top card

        int rank = c.GetRank();

        cVect[rank].insert(cVect[rank].begin(), c); // Put the card under the pile
        Card cTop = cVect[rank].back(); // Get the top card

        startDeck = rank;
        if(cTop.GetRank() == Card::King)
        {
            kingCount++;

            if(kingCount >= 4)
            {
                // Lose
                cout << "You have lost!" << endl;
                break;
            }
            cVect[rank].pop_back(); // Remove the card if its king
            cVect[0].insert(cVect[0].begin(), cTop); // Put the king under the pile
        }

        revealedCount++;

        if(revealedCount >= 48)
        {
            // Win
            cout << "You have won!" << endl;
            break;
        }
    }

    return 0;
}
