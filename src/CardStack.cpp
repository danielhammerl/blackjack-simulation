//
// Created by Daniel Hammerl on 31.07.23.
//

#include "CardStack.h"
#include "GameSettings.h"
#include <algorithm>
#include <random>
#include <vector>

CardStack::CardStack() {
 this->reset();
}

void CardStack::reset() {
    cardList.clear();

    for (int deck = 0; deck < GameSettings::numberOfCardDecks; deck++) {
        for (int value = CardValue::Ace; value <= CardValue::King; value++) {
            for (int color = CardColor::Heart; color <= CardColor::Space; color++) {
                Card x = Card(static_cast<CardValue>(value), static_cast<CardColor>(color));
                cardList.push_back(x);
            }
        }
    }
}

std::list<Card> CardStack::getCardList() {
    return cardList;
}

void CardStack::shuffle() {
    std::random_device rd;
    std::mt19937 generator(rd());

    std::vector<Card> tempVector(cardList.begin(), cardList.end());
    std::shuffle(tempVector.begin(), tempVector.end(), generator);

    cardList.assign(tempVector.begin(), tempVector.end());
}

Card CardStack::draw() {
    Card card = cardList.back();
    cardList.pop_back();
    return card;
}
