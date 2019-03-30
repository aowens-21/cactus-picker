//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_GAME_H
#define CACTUS_PICKER_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "GameStateSystem.h"

class Game
{
private:
    // Game will have control over the window
    sf::RenderWindow window {sf::VideoMode(800, 800), "Cactus Picker"};

    // For event polling
    sf::Event current_event;

    // Keeping track of if the game is still running
    bool is_running = true;
public:
    Game();

    // Tells main if the game is still running
    bool is_game_running() const noexcept { return is_running; }

    // Runs main loop based on the game state
    void run_main_loop(const GameState& state);
};

#endif //CACTUS_PICKER_GAME_H
