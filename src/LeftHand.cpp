//
// Created by alex on 3/31/19.
//

#include <SFML/Window/Keyboard.hpp>
#include "../include/LeftHand.h"

void LeftHand::process_grab_movement(const sf::FloatRect &cactus_rect)
{
    if (grabbing)
    {
        rect.left += GRAB_VELOCITY;

        if (rect.intersects(cactus_rect))
        {
            grabbing = false;
            recovering_from_grab = true;
        }
    }
    else if (recovering_from_grab)
    {
        rect.left -= GRAB_VELOCITY;

        if (rect.left <= initial_position.x)
        {
            recovering_from_grab = false;
            rect.left = initial_position.x;
        }
    }
}

void LeftHand::update(const sf::FloatRect& cactus_rect)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        process_ascent();
    }
    else
    {
        process_descent();
    }

    process_grab_movement(cactus_rect);

    sprite.setPosition(rect.left, rect.top);
}