//
// Created by alex on 3/30/19.
//

#include "../include/Game.h"

// Initial game construction setup
Game::Game()
{
    window.setFramerateLimit(60);
    game_font.loadFromFile("../images/roboto.ttf");
    init_time_display();
}

// Runs main loop based on a given state
void Game::run_main_loop(GameStateSystem &state_system)
{
    while (window.pollEvent(current_event))
    {
        if (current_event.type == sf::Event::Closed)
        {
            is_running = false;
        }
        else if (current_event.type == sf::Event::KeyPressed)
        {
            if (current_event.key.code == sf::Keyboard::W)
            {
                left_hand.grab();
            }
            else if (current_event.key.code == sf::Keyboard::O)
            {
                right_hand.grab();
            }
        }
    }

    window.clear();

    if (state_system.get_state() == GameState::Playing)
    {
        if (cactus.get_remaining_spike_count() > 0)
        {
            update_time();
        }
        else
        {
            state_system.change_state(GameState::Won);
        }
        cactus.update();
    }

    right_hand.update(cactus);
    left_hand.update(cactus);

    left_hand.draw(window);
    right_hand.draw(window);
    cactus.draw(window);
    window.draw(time_display);

    window.display();
}

void Game::update_time()
{
    sf::Int32 elapsed_milliseconds = clock.getElapsedTime().asMilliseconds();
    time_display.setString(std::to_string(elapsed_milliseconds / 1000) + "." + std::to_string(elapsed_milliseconds % 1000 / 10));
}

void Game::init_time_display()
{
    time_display.setFont(game_font);
    time_display.setPosition(WINDOW_WIDTH/2 - 20, 20);
}