//
// Created by alex on 3/31/19.
//

#include <SFML/Window/Keyboard.hpp>
#include "../include/LeftHand.h"

void LeftHand::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        process_ascent();
    }
    else
    {
        process_descent();
    }

    sprite.setPosition(rect.left, rect.top);
}