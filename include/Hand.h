//
// Created by alex on 3/31/19.
//

#ifndef CACTUS_PICKER_HAND_H
#define CACTUS_PICKER_HAND_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

constexpr const float INIT_VERTICAL_VELOCITY = 10.0;
constexpr const float GRAVITY = 2.0;

class Hand
{
private:
    // For vertical movement speed
    float vertical_velocity = INIT_VERTICAL_VELOCITY;

    // Sprite for the hand
    sf::Texture texture;
    sf::Sprite sprite;

    // Rect for collision and physics
    sf::FloatRect rect;
public:
    Hand(float x, float y, const std::string& texture_path);

    // Draw will render our sprite
    void draw(sf::RenderWindow& window);
};

#endif //CACTUS_PICKER_HAND_H
