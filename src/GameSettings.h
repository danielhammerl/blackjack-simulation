//
// Created by Daniel Hammerl on 31.07.23.
//

#ifndef BLACKJACK_SIMULATION_GAMESETTINGS_H
#define BLACKJACK_SIMULATION_GAMESETTINGS_H

class GameSettings {
public:
    static const unsigned betPerRound = 1;
    static const unsigned numberOfCardDecks = 4;
    constexpr static const float blackJackPays = 2.5f;
    constexpr static const float insurancePays = 2.f;
    static const unsigned dealerBuysUntil = 17;
};

#endif //BLACKJACK_SIMULATION_GAMESETTINGS_H
