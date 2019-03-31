//
// Created by alex on 3/31/19.
//

#include <SFML/Graphics/Texture.hpp>
#include "../include/Cactus.h"

Cactus::Cactus(float x, float y)
{
    // Set up the sprite's texture
    texture.loadFromFile("../images/cactus.png");
    sprite.setTexture(texture);

    // Set up positions and rect
    rect.left = x;
    rect.top = y;
    rect.width = texture.getSize().x;
    rect.height = texture.getSize().y;

    sprite.setPosition(x, y);
}

void Cactus::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}