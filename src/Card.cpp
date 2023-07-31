//
// Created by Daniel Hammerl on 31.07.23.
//

#include "Card.h"
#include <sstream>

Card::Card(CardValue _value, CardColor _color): value(_value), color(_color) {

}

std::string Card::toString() {
    std::stringstream ss;
    ss << CardColorNames.at(color);
    ss << " ";
    ss << CardValueNames.at(value);
    return ss.str();
}
