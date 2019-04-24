//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_CACTUS_H
#define CACTUS_PICKER_CACTUS_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Spike.h"
#include "Hand.h"

class Cactus
{
private:
    sf::Texture spike_texture;

    sf::Texture cactus_texture;
    sf::Sprite sprite;

    sf::SoundBuffer poked_sound_buffer;
    sf::SoundBuffer plucked_sound_buffer;
    sf::Sound poked_sound;
    sf::Sound plucked_spike_sound;


    sf::FloatRect rect;

    // Container of spikes
    std::vector<Spike> spikes;
public:
    Cactus(float x, float y);

    void draw(sf::RenderWindow& window);

    sf::FloatRect get_rect() const { return rect; }

    bool handle_spike_collisions(Hand* hand);

    void update();

    size_t get_remaining_spike_count() const { return spikes.size(); }

    // Sets up all the spikes on the cactus
    void setup_spikes();
};

#endif //CACTUS_PICKER_CACTUS_H
