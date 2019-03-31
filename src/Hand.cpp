//
// Created by alex on 3/31/19.
//

#include <SFML/Graphics/Texture.hpp>
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
    rect.height = texture.getSize().y;

    sprite.setPosition(x, y);

    initial_position.x = x;
    initial_position.y = y;
}

void Hand::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}