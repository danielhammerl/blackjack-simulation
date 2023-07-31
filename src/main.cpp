#include <iostream>
#include "CardStack.h"
#include "util.h"
#include "GameSettings.h"
#include <vector>

void playerMove(std::vector<Card> &playerCards, Card dealerCard, CardStack &cardStack) {
    int playerValue = calcCardsValues(playerCards);

    while(playerValue < 17) {
        playerCards.push_back(cardStack.draw());
        playerValue = calcCardsValues(playerCards);
    }
}

double doRound(CardStack &cardStack) {
    std::vector<Card> playerCards;
    std::vector<Card> dealerCards;

    // player and dealer get two cards
    playerCards.push_back(cardStack.draw());
    dealerCards.push_back(cardStack.draw());
    playerCards.push_back(cardStack.draw());
    dealerCards.push_back(cardStack.draw());

    Card dealerVisibleCard = dealerCards[0];

    int playerValue = calcCardsValues(playerCards);
    int dealerValue = calcCardsValues(dealerCards);

    if (playerValue == 21) {
        //Blackjack!
        if (dealerValue == 21) {
            return 0;
        } else {
            return GameSettings::betPerRound * GameSettings::blackJackPays;
        }
    }
    // player does stuff
    playerMove(playerCards, dealerVisibleCard, cardStack);
    playerValue = calcCardsValues(playerCards);

    if(playerValue > 21) {
        return static_cast<double>(GameSettings::betPerRound) * -1;
    }

    // dealer does stuff
    while (dealerValue < GameSettings::dealerBuysUntil) {
        dealerCards.push_back(cardStack.draw());
        dealerValue = calcCardsValues(dealerCards);
    }

    if (dealerValue > 21) {
        // dealer busted
        return GameSettings::betPerRound;
    }

    if (playerValue > dealerValue) {
        return GameSettings::betPerRound;
    } else if(playerValue == dealerValue) {
        return 0;
    }

    return static_cast<double>(GameSettings::betPerRound) * -1;
}

int main() {
    CardStack cardStack = CardStack();
    cardStack.shuffle();
    long double playerMoney = 0;
    unsigned long numberOfRounds = 1000000;

    for (unsigned long round = 0; round < numberOfRounds; round++) {
        playerMoney += doRound(cardStack);
        cardStack.reset();
        cardStack.shuffle();
    }

    std::cout << playerMoney << " (" << ((playerMoney / static_cast<long double>(numberOfRounds)) * 100) << " %)";
}
