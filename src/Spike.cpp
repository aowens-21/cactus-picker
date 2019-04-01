//
// Created by alex on 4/1/19.
//

#include "../include/Spike.h"
#include "SFML/Graphics/Texture.hpp"

Spike::Spike(float x, float y, const sf::Texture &texture)
{
    sprite.setTexture(texture);

    rect.left = x;
    rect.top = y;
    rect.width = texture.getSize().x;
    rect.height = texture.getSize().y;

    sprite.setPosition(x, y);
}

void Spike::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
