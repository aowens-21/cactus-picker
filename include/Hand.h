//
// Created by alex on 3/31/19.
//

#ifndef CACTUS_PICKER_HAND_H
#define CACTUS_PICKER_HAND_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

constexpr const int HITBOX_WIDTH = 43;
constexpr const int HITBOX_HEIGHT = 28;
constexpr const int RECT_HEIGHT_OFFSET = 10;

class Hand
{
protected:
    // For vertical movement speed
    float ascent_velocity = INIT_ASCENT_VELOCITY;
    float descent_velocity = GRAVITY;

    // Physics tweaking
    static constexpr const float GRAVITY = 2.0;
    static constexpr const float ACCELERATION = 0.4;
    static constexpr const float MAX_VELOCITY = 18.0;
    static constexpr const float MAX_FALL_VELOCITY = 20.0;
    static constexpr const float INIT_ASCENT_VELOCITY = 4.0;

    // Speed of grab motion
    static constexpr const float GRAB_VELOCITY = 25.0;

    // Window height for bounds checking
    float min_y = 0.0;

    // Sprite for the hand
    sf::Texture texture;
    sf::Sprite sprite;

    // Rect for collision and physics
    sf::FloatRect rect;
    sf::FloatRect hitbox;

    // Keeping track of initial x and y position
    sf::Vector2f initial_position;

    // Tells whether or not the hand is in the grab state and recovering state
    bool grabbing = false;
    bool recovering_from_grab = false;

    // Processes the physics behind ascent of the hand
    void process_ascent();

    // Processes the physics behind the descent of the hand
    void process_descent();

    // Processes grab physics of derived class
    virtual void process_grab_movement(const sf::FloatRect& cactus_rect)=0;
public:
    Hand(float x, float y, const std::string& texture_path);

    // Draw will render our sprite
    void draw(sf::RenderWindow& window);

    // Sets grabbing state as true
    void grab();

    sf::FloatRect get_rect() const { return rect; }

    sf::FloatRect get_hitbox_rect() const { return hitbox; }

    void reset();

    bool is_recovering_from_grab() const { return recovering_from_grab; }

    virtual ~Hand()= default;
};

#endif //CACTUS_PICKER_HAND_H
