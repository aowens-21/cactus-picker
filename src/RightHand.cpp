//
// Created by alex on 3/31/19.
//

#include <SFML/Window/Keyboard.hpp>
#include "../include/RightHand.h"
#include "../include/Cactus.h"

RightHand::RightHand(float x, float y): Hand(x, y, "../images/right_hand.png")
{
    // Set up hitbox coordinates
    update_hitbox();
}

void RightHand::update_hitbox()
{
    hitbox.left = rect.left;
    hitbox.top = rect.top + 12;
}

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

void RightHand::update(Cactus &cactus, GameStateSystem& state_system)
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
    update_hitbox();

    if (state_system.get_state() == GameState::Playing)
    {
        auto poked_by_spike = cactus.handle_spike_collisions(this);
        if (poked_by_spike)
        {
            state_system.change_state(GameState::Lost);
            reset();
        }
    }

    sprite.setPosition(rect.left, rect.top);
}