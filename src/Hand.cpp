//
// Created by alex on 3/31/19.
//

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../include/Hand.h"

Hand::Hand(float x, float y, const std::string &texture_path)
{
    // Set up the sprite's texture
    texture.loadFromFile(texture_path);
    sprite.setTexture(texture);

    // Set up positions and rect
    rect.left = x;
    rect.top = y;
    rect.width = texture.getSize().x;
    rect.height = texture.getSize().y - static_cast<float>(texture.getSize().y)/2 + RECT_HEIGHT_OFFSET;

    // Set up the hitbox rect size
    hitbox.width = HITBOX_WIDTH;
    hitbox.height = HITBOX_HEIGHT;

    sprite.setPosition(x, y);

    initial_position.x = x;
    initial_position.y = y;

    // used to clamp the ascension of the hands
    min_y = rect.height * 2.0f;
}

void Hand::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void Hand::process_ascent()
{
    if (rect.top > min_y)
    {
        // Reset the descent velocity since we aren't yet falling
        descent_velocity = GRAVITY;
        // While ascent velocity is not at max, we keep increasing it
        if (ascent_velocity < MAX_VELOCITY)
        {
            ascent_velocity += ACCELERATION;
        }

        rect.top -= ascent_velocity;
    }
}

void Hand::process_descent()
{
    // Only fall if not grabbing
    if (!grabbing && !recovering_from_grab)
    {
        // If we aren't ascending, the ascent velocity needs to be reset
        ascent_velocity = INIT_ASCENT_VELOCITY;

        // While we haven't hit the ground, fall
        if (rect.top < initial_position.y)
        {
            if (descent_velocity < MAX_FALL_VELOCITY)
            {
                descent_velocity += ACCELERATION;
            }

            rect.top += descent_velocity;
        } else
        {
            rect.top = initial_position.y;
        }
    }
}

void Hand::grab()
{
    if (!grabbing && !recovering_from_grab)
    {
        grabbing = true;
    }
}

void Hand::reset()
{
    rect.left = initial_position.x;
    rect.top = initial_position.y;
    sprite.setPosition(rect.left, rect.top);
    grabbing = false;
    recovering_from_grab = false;
}