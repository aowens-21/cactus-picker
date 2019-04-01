//
// Created by alex on 3/31/19.
//

#include <SFML/Window/Keyboard.hpp>
#include "../include/RightHand.h"

void RightHand::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        process_ascent();
    }
    else
    {
        process_descent();
    }

    sprite.setPosition(rect.left, rect.top);
}