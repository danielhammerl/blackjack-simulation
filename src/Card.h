//
// Created by Daniel Hammerl on 31.07.23.
//

#ifndef BLACKJACK_SIMULATION_CARD_H
#define BLACKJACK_SIMULATION_CARD_H

#include <map>
#include <string>

enum CardValue {
    Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
};

enum CardColor {
    Heart, Diamond, Club, Space
};

static const std::map<CardColor, std::string> CardColorNames = {
        {
                Heart, "Heart"
        },
        {
                Diamond, "Diamond"
        },
        {
                Club, "Club"
        },
        {
                Space, "Space"
        }
};

static const std::map<CardValue, std::string> CardValueNames = {
        {
                Ace,   "Ace"
        },
        {
                Two,   "Two"
        },
        {
                Three, "Three"
        },
        {
                Four,  "Four"
        },
        {
                Five,  "Five"
        },
        {
                Six,   "Six"
        },
        {
                Seven, "Seven"
        },
        {
                Eight, "Eight"
        },
        {
                Nine,  "Nine"
        },
        {
                Ten,   "Ten"
        },
        {
                Jack,  "Jack"
        },
        {
                Queen, "Queen"
        },
        {
                King,  "King"
        }
};

class Card {
public:
    Card(CardValue _value, CardColor _color);

    [[nodiscard]] CardValue getValue() const {
        return value;
    }
    std::string toString();

private:
    CardValue value;
    CardColor color;
};


#endif //BLACKJACK_SIMULATION_CARD_H
