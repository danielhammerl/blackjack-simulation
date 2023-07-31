//
// Created by Daniel Hammerl on 31.07.23.
//

#ifndef BLACKJACK_SIMULATION_CARDSTACK_H
#define BLACKJACK_SIMULATION_CARDSTACK_H

#include <list>
#include "Card.h"


class CardStack {
public:
    CardStack();

    void reset();
    void shuffle();
    std::list<Card> getCardList();

    Card draw();

private:

    std::list<Card> cardList;

};


#endif //BLACKJACK_SIMULATION_CARDSTACK_H
