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
    RightHand right_hand = RightHand(600, 500);
    LeftHand left_hand = LeftHand(100, 500);
    Cactus cactus = Cactus(300, 100);
public:
    Game();

    // Tells main if the game is still running
    bool is_game_running() const noexcept { return is_running; }

    // Runs main loop based on the game state
    void run_main_loop(const GameState& state);
};

#endif //CACTUS_PICKER_GAME_H
