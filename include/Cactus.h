//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_CACTUS_H
#define CACTUS_PICKER_CACTUS_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Spike.h"
#include "Hand.h"

class Cactus
{
private:
    sf::Texture spike_texture;

    sf::Texture cactus_texture;
    sf::Sprite sprite;

    sf::FloatRect rect;

    // Container of spikes
    std::vector<Spike> spikes;

    // Sets up all the spikes on the cactus
    void setup_spikes();
public:
    Cactus(float x, float y);

    void draw(sf::RenderWindow& window);

    sf::FloatRect get_rect() const { return rect; }

    void handle_spike_collisions(Hand* hand);

    void update();
};

#endif //CACTUS_PICKER_CACTUS_H
