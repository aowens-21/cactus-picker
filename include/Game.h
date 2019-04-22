//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_GAME_H
#define CACTUS_PICKER_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "GameStateSystem.h"
#include "RightHand.h"
#include "Cactus.h"
#include "LeftHand.h"

constexpr const float INIT_HAND_Y = 670;
constexpr const float INIT_LEFT_HAND_X = 0;
constexpr const float INIT_RIGHT_HAND_X = 900;
constexpr const float INIT_CACTUS_X = 380;
constexpr const float INIT_CACTUS_Y = 55;
constexpr const int WINDOW_WIDTH = 1024;
constexpr const int WINDOW_HEIGHT = 800;

// Singleton to represent the game as a whole, managing the actors and game state
class Game
{
private:
    // Game will have control over the window
    sf::RenderWindow window {sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Cactus Picker"};

    // Game's background image
    sf::Texture bg_texture;
    sf::Sprite bg_sprite;

    // For event polling
    sf::Event current_event;

    // Keeping track of if the game is still running
    bool is_running = true;

    // All of the main game members
    RightHand right_hand = RightHand(INIT_RIGHT_HAND_X, INIT_HAND_Y);
    LeftHand left_hand = LeftHand(INIT_LEFT_HAND_X, INIT_HAND_Y);
    Cactus cactus = Cactus(INIT_CACTUS_X, INIT_CACTUS_Y);

    // Clock for the timer
    sf::Clock clock;
    sf::Font game_font;

    // Time as a string
    sf::Text time_display;

    void update_time();

    void init_time_display();
public:
    Game();

    // Tells main if the game is still running
    bool is_game_running() const noexcept { return is_running; }

    // Runs main loop based on the game state system
    void run_main_loop(GameStateSystem& state_system);
};

#endif //CACTUS_PICKER_GAME_H
