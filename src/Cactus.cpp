//
// Created by alex on 3/31/19.
//

#include <SFML/Graphics/Texture.hpp>
#include "../include/Cactus.h"

Cactus::Cactus(float x, float y)
{
    // Set up the sprite's texture
    cactus_texture.loadFromFile("../images/cactus.png");
    sprite.setTexture(cactus_texture);

    // Set up the spike's texture
    spike_texture.loadFromFile("../images/spike.png");

    // Set up positions and rect
    rect.left = x;
    rect.top = y;
    rect.width = cactus_texture.getSize().x;
    rect.height = cactus_texture.getSize().y;

    sprite.setPosition(x, y);

    // Set up the spikes
    setup_spikes();
}

void Cactus::setup_spikes()
{
    spikes.emplace_back(Spike(rect.left - 40, 300, spike_texture));
    spikes.emplace_back(Spike(rect.left - 40, 400, spike_texture));
    spikes.emplace_back(Spike(rect.left - 40, 600, spike_texture));
    spikes.emplace_back(Spike(rect.left + rect.width - 10, 200, spike_texture));
    spikes.emplace_back(Spike(rect.left + rect.width - 10, 500, spike_texture));
    spikes.emplace_back(Spike(rect.left + rect.width - 10, 700, spike_texture));

}

void Cactus::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    for (auto& spike : spikes)
    {
        spike.draw(window);
    }
}

void Cactus::handle_spike_collisions(Hand *hand)
{
    sf::FloatRect hand_rect = hand->get_rect();
    sf::FloatRect hand_hitbox_rect = hand->get_hitbox_rect();

    for (auto& spike : spikes)
    {
        if (hand_hitbox_rect.intersects(spike.get_rect()))
        {
            spike.set_grabbed();
        }
    }
}

void Cactus::update()
{
    spikes.erase(std::remove_if(spikes.begin(), spikes.end(), [](Spike& spike) { return spike.is_grabbed(); })
            , spikes.end());
}