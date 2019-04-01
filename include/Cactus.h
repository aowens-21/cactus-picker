//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_CACTUS_H
#define CACTUS_PICKER_CACTUS_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

class Cactus
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

    sf::FloatRect rect;
public:
    Cactus(float x, float y);

    void draw(sf::RenderWindow& window);

    sf::FloatRect get_rect() const { return rect; }
};

#endif //CACTUS_PICKER_CACTUS_H
