//
// Created by alex on 3/31/19.
//

#include <SFML/Window/Keyboard.hpp>
#include "../include/RightHand.h"

void RightHand::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        rect.top -= vertical_velocity;
    }
    else
    {
        if (rect.top < initial_position.y)
        {
            rect.top += GRAVITY;
        } else
        {
            rect.top = initial_position.y;
        }
    }

    sprite.setPosition(rect.left, rect.top);
}