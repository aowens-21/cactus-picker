//
// Created by alex on 3/30/19.
//

#include "../include/Game.h"

// Initial game construction setup
Game::Game()
{
    window.setFramerateLimit(60);
}

// Runs main loop based on a given state
void Game::run_main_loop(const GameState &state)
{
    while (window.pollEvent(current_event))
    {
        if (current_event.type == sf::Event::Closed)
        {
            is_running = false;
        }
    }

    window.clear();

    right_hand.update();
    left_hand.update();

    left_hand.draw(window);
    right_hand.draw(window);
    cactus.draw(window);

    window.display();
}