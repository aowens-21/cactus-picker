//
// Created by alex on 4/1/19.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include "../include/Spike.h"
#include "SFML/Graphics/Texture.hpp"

Spike::Spike(float x, float y, const sf::Texture &texture, bool flipped)
{
    sprite.setTexture(texture);

    rect.left = x;
    rect.top = y;
    rect.width = texture.getSize().x;
    rect.height = texture.getSize().y;

    sprite.setPosition(x, y);

    if (flipped) {
        sprite.setScale(-1.0f, 1.0f);
        rect.left = rect.left - rect.width;
    }
}

void Spike::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
