//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_GAME_H
#define CACTUS_PICKER_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "GameStateSystem.h"
#include "RightHand.h"
#include "Cactus.h"
#include "LeftHand.h"

constexpr const float INIT_HAND_Y = 670;
constexpr const float INIT_LEFT_HAND_X = 50;
constexpr const float INIT_RIGHT_HAND_X = 880;
constexpr const float INIT_CACTUS_X = 380;
constexpr const float INIT_CACTUS_Y = 70;

// Singleton to represent the game as a whole, managing the actors and game state
class Game
{
private:
    // Game will have control over the window
    sf::RenderWindow window {sf::VideoMode(1024, 800), "Cactus Picker"};

    // For event polling
    sf::Event current_event;

    // Keeping track of if the game is still running
    bool is_running = true;

    // All of the main game members
    RightHand right_hand = RightHand(INIT_RIGHT_HAND_X, INIT_HAND_Y);
    LeftHand left_hand = LeftHand(INIT_LEFT_HAND_X, INIT_HAND_Y);
    Cactus cactus = Cactus(INIT_CACTUS_X, INIT_CACTUS_Y);
public:
    Game();

    // Tells main if the game is still running
    bool is_game_running() const noexcept { return is_running; }

    // Runs main loop based on the game state
    void run_main_loop(const GameState& state);
};

#endif //CACTUS_PICKER_GAME_H
