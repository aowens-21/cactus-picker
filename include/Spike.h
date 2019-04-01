//
// Created by alex on 4/1/19.
//

#ifndef CACTUS_PICKER_SPIKE_H
#define CACTUS_PICKER_SPIKE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Spike
{
private:
    sf::Sprite sprite;
    sf::FloatRect rect;

    bool grabbed = false;
public:
    Spike(float x, float y, const sf::Texture& texture);

    void draw(sf::RenderWindow& window);

    sf::FloatRect get_rect() const { return rect; }

    void set_grabbed() { grabbed = true; }

    bool is_grabbed() const { return grabbed; }
};

#endif //CACTUS_PICKER_SPIKE_H
