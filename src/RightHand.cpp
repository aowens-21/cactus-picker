//
// Created by alex on 3/31/19.
//

#include <SFML/Window/Keyboard.hpp>
#include "../include/RightHand.h"
#include "../include/Cactus.h"

void RightHand::process_grab_movement(const sf::FloatRect& cactus_rect)
{
    if (grabbing)
    {
        rect.left -= GRAB_VELOCITY;

        if (rect.intersects(cactus_rect))
        {
            grabbing = false;
            recovering_from_grab = true;
        }
    }
    else if (recovering_from_grab)
    {
        rect.left += GRAB_VELOCITY;

        if (rect.left >= initial_position.x)
        {
            recovering_from_grab = false;
            rect.left = initial_position.x;
        }
    }
}

void RightHand::update(Cactus &cactus)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        process_ascent();
    }
    else
    {
        process_descent();
    }

    process_grab_movement(cactus.get_rect());
    cactus.handle_spike_collisions(this);

    sprite.setPosition(rect.left, rect.top);
}