//
// Created by alex on 3/30/19.
//

#include "../include/Game.h"

// Initial game construction setup
Game::Game()
{
    window.setFramerateLimit(60);
    game_font.loadFromFile("../images/manaspc.ttf");

    // Set up bg
    bg_texture.loadFromFile("../images/bg.png");
    bg_sprite.setTexture(bg_texture);
    bg_sprite.setPosition(0, 0);

    // Set up controls images
    q_texture.loadFromFile("../images/q_lift.png");
    q_sprite.setTexture(q_texture);
    q_sprite.setPosition(20, 20);

    w_texture.loadFromFile("../images/w_grab.png");
    w_sprite.setTexture(w_texture);
    w_sprite.setPosition(140, 20);

    p_texture.loadFromFile("../images/p_lift.png");
    p_sprite.setTexture(p_texture);
    p_sprite.setPosition(904, 20);

    o_texture.loadFromFile("../images/o_grab.png");
    o_sprite.setTexture(o_texture);
    o_sprite.setPosition(784, 20);

    timer_bg_texture.loadFromFile("../images/timer_bg.png");
    timer_bg_sprite.setTexture(timer_bg_texture);
    timer_bg_sprite.setPosition(INIT_CACTUS_X + 50, INIT_CACTUS_Y - 100);
    init_time_display();
}

// Runs main loop based on a given state
void Game::run_main_loop(GameStateSystem &state_system)
{
    GameState state = state_system.get_state();

    while (window.pollEvent(current_event))
    {
        if (current_event.type == sf::Event::Closed)
        {
            is_running = false;
        }
        else if (current_event.type == sf::Event::KeyPressed && state != GameState::MainMenu)
        {
            if (current_event.key.code == sf::Keyboard::W)
            {
                left_hand.grab();
            }
            else if (current_event.key.code == sf::Keyboard::O)
            {
                right_hand.grab();
            }
            else if (current_event.key.code == sf::Keyboard::R)
            {
                state_system.change_state(GameState::Restarting);
            }
        }
        else if (current_event.type == sf::Event::MouseButtonPressed && state == GameState::MainMenu) {
            if (current_event.mouseButton.button == sf::Mouse::Left) {
                main_menu.handle_click(state_system, window);
            }
        }
    }

    window.clear();

    if (state == GameState::Playing)
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

    if (state != GameState::MainMenu)
    {
        right_hand.update(cactus, state_system);
        left_hand.update(cactus, state_system);

        window.draw(bg_sprite);
        left_hand.draw(window);
        right_hand.draw(window);
        cactus.draw(window);
        window.draw(q_sprite);
        window.draw(w_sprite);
        window.draw(p_sprite);
        window.draw(o_sprite);
        window.draw(timer_bg_sprite);
        window.draw(time_display);
    }

    if (state == GameState::Lost)
    {
        retry_menu.update(right_hand, left_hand, state_system);
        retry_menu.draw(window);
    }
    else if (state == GameState::Restarting)
    {
        start_game();
        state_system.change_state(GameState::Playing);
        clock.restart();
    }
    else if (state == GameState::Exiting)
    {
        is_running = false;
    }
    else if (state == GameState::MainMenu)
    {
        main_menu.draw(window);
    }

    window.display();
}

void Game::update_time()
{
    sf::Int32 elapsed_milliseconds = clock.getElapsedTime().asMilliseconds();
    time_display.setString(std::to_string(elapsed_milliseconds / 1000) + "." + std::to_string(elapsed_milliseconds % 1000 / 10));
}

void Game::init_time_display()
{
    auto timer_bg_pos = timer_bg_sprite.getPosition();
    time_display.setFont(game_font);
    time_display.setPosition(timer_bg_pos.x + 25, timer_bg_pos.y + 48);
}

void Game::start_game()
{
    right_hand.reset();
    left_hand.reset();
    cactus.setup_spikes();
}