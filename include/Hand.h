//
// Created by alex on 3/31/19.
//

#ifndef CACTUS_PICKER_HAND_H
#define CACTUS_PICKER_HAND_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

class Hand
{
protected:
    // For vertical movement speed
    float ascent_velocity = INIT_ASCENT_VELOCITY;
    float descent_velocity = GRAVITY;

    // Physics tweaking
    static constexpr float GRAVITY = 2.0;
    static constexpr float ACCELERATION = 0.4;
    static constexpr float MAX_VELOCITY = 18.0;
    static constexpr float MAX_FALL_VELOCITY = 20.0;
    static constexpr float INIT_ASCENT_VELOCITY = 4.0;

    // Sprite for the hand
    sf::Texture texture;
    sf::Sprite sprite;

    // Rect for collision and physics
    sf::FloatRect rect;

    // Keeping track of initial x and y position
    sf::Vector2f initial_position;

    // Processes the physics behind ascent of the hand
    void process_ascent();

    // Processes the physics behind the descent of the hand
    void process_descent();
public:
    Hand(float x, float y, const std::string& texture_path);

    // Draw will render our sprite
    void draw(sf::RenderWindow& window);
};

#endif //CACTUS_PICKER_HAND_H
