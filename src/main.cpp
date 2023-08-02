#include <iostream>
#include "CardStack.h"
#include "util.h"
#include "GameSettings.h"
#include <vector>

void
playerMove(std::vector<std::vector<Card>> &playerStacks, Card dealerCard, CardStack &cardStack, unsigned &currentBet) {
    for (auto &stack: playerStacks) {
        // player can move with every stack he has
        int playerValue = calcCardsValues(stack);

        // player strategy
        while (playerValue < 17) {
            stack.push_back(cardStack.draw());
            playerValue = calcCardsValues(stack);
        }
    }
}

double doRound(CardStack &cardStack) {
    unsigned currentBet = GameSettings::betPerRound;
    std::vector<std::vector<Card>> playerStacks;
    std::vector<Card> dealerCards;
    playerStacks.emplace_back();

    // player and dealer get two cards
    playerStacks[0].push_back(cardStack.draw());
    dealerCards.push_back(cardStack.draw());
    playerStacks[0].push_back(cardStack.draw());
    dealerCards.push_back(cardStack.draw());

    Card dealerVisibleCard = dealerCards[0];

    int dealerValue = calcCardsValues(dealerCards);

    if (calcCardsValues(playerStacks[0]) == 21) {
        //Blackjack!
        if (dealerValue == 21) {
            return 0;
        } else {
            return static_cast<double>(currentBet) * GameSettings::blackJackPays;
        }
    }
    // player does stuff
    playerMove(playerStacks, dealerVisibleCard, cardStack, currentBet);


    double result = 0;

    for (int index = 0; index < playerStacks.size(); index++) {
        auto stack = playerStacks[index];
        int playerValue = calcCardsValues(stack);
        if (playerValue > 21) {
            result += static_cast<double>(currentBet) * -1;
            playerStacks.erase(playerStacks.begin() + index);
        }
    }

    // dealer does stuff
    while (dealerValue < GameSettings::dealerBuysUntil) {
        dealerCards.push_back(cardStack.draw());
        dealerValue = calcCardsValues(dealerCards);
    }

    for (const auto &stack: playerStacks) {
        int playerValue = calcCardsValues(stack);

        if (dealerValue > 21) {
            // dealer busted
            result += static_cast<double>(currentBet);
        } else if (playerValue > dealerValue) {
            // player won by higher card value
            result += static_cast<double>(currentBet);
        } else if (playerValue == dealerValue) {
            // player and dealer have same value
        } else {
            // player has less than dealer and lost
            result += static_cast<double>(currentBet) * -1;
        }
    }

    return result;
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
