//
// Created by alex on 3/31/19.
//

#include <SFML/Window/Keyboard.hpp>
#include "../include/LeftHand.h"
#include "../include/Cactus.h"

LeftHand::LeftHand(float x, float y): Hand(x, y, "../images/left_hand.png")
{
    update_hitbox();
}

void LeftHand::update_hitbox()
{
    // Set up hitbox coordinates
    hitbox.left = (rect.left + rect.width) - HITBOX_WIDTH;
    hitbox.top = rect.top + 13;
}

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

void LeftHand::update(Cactus &cactus)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        process_ascent();
    }
    else
    {
        process_descent();
    }

    process_grab_movement(cactus.get_rect());
    update_hitbox();
    cactus.handle_spike_collisions(this);

    sprite.setPosition(rect.left, rect.top);
}