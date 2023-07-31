//
// Created by Daniel Hammerl on 31.07.23.
//

#include <map>
#include <vector>
#include "Card.h"

#ifndef BLACKJACK_SIMULATION_UTIL_H
#define BLACKJACK_SIMULATION_UTIL_H


static const std::map<CardValue, int> cardValueInPointsWithoutAce = {
        {
                CardValue::Two, 2
        },
        {
                CardValue::Three, 3,
        },
        {
                CardValue::Four, 4
        },
        {
                CardValue::Five, 5
        },
        {
                CardValue::Six, 6
        },
        {
                CardValue::Seven, 7
        },
        {
                CardValue::Eight, 8
        },
        {
                CardValue::Nine, 9
        },
        {
                CardValue::Ten, 10
        },
        {
                CardValue::Jack, 10
        },
        {
                CardValue::Queen, 10
        },
        {
                CardValue::King, 10
        }
};

static int calcCardsValues(std::vector<Card> cards) {
    int value = 0;

    std::vector<Card> cardsWithoutAces;
    std::vector<Card> aces;

    std::copy_if(cards.begin(), cards.end(), std::back_inserter(cardsWithoutAces),
                 [&](const Card &element) { return element.getValue() != CardValue::Ace; });

    std::copy_if(cards.begin(), cards.end(), std::back_inserter(aces),
                 [&](const Card &element) { return element.getValue() == CardValue::Ace; });

    for (auto card: cardsWithoutAces) {
        value += cardValueInPointsWithoutAce.at(card.getValue());
    }

    for (auto _: aces) {
        if (value + 11 > 21) {
            value += 1;
        } else {
            value += 11;
        }
    }

    return value;
}

#endif //BLACKJACK_SIMULATION_UTIL_H
