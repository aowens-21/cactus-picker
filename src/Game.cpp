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

    window.clear();

    switch (state) {
        case GameState::MainMenu: {
            run_main_menu(state_system);
            break;
        }

        case GameState::Playing: {
            run_playing(state_system);
            break;
        }

        case GameState::Won: {
            run_won(state_system);
            break;
        }

        case GameState::Lost: {
            run_lost(state_system);
            break;
        }

        case GameState::Restarting: {
            run_restarting(state_system);
            break;
        }

        case GameState::Exiting: {
            run_exiting();
            break;
        }
    }

    window.display();
}

void Game::run_main_menu(GameStateSystem &state_system)
{
    while (window.pollEvent(current_event))
    {
        if (current_event.type == sf::Event::Closed) {
            is_running = false;
        } else if (current_event.type == sf::Event::MouseButtonPressed) {
            if (current_event.mouseButton.button == sf::Mouse::Left) {
                main_menu.handle_click(state_system, window);
            }
        }
    }

    main_menu.draw(window);
}

void Game::run_playing(GameStateSystem &state_system)
{
    handle_gameplay_events(state_system);

    if (cactus.get_remaining_spike_count() > 0)
    {
        update_time();
    }
    else
    {
        state_system.change_state(GameState::Won);
    }
    cactus.update();

    right_hand.update(cactus, state_system);
    left_hand.update(cactus, state_system);

    render_gameplay_entities();
}

void Game::run_restarting(GameStateSystem &state_system)
{
    start_game();
    state_system.change_state(GameState::Playing);
    clock.restart();

    render_gameplay_entities();
}

void Game::run_exiting()
{
    is_running = false;
}

void Game::run_lost(GameStateSystem &state_system)
{
    handle_gameplay_events(state_system);

    right_hand.update(cactus, state_system);
    left_hand.update(cactus, state_system);

    render_gameplay_entities();

    retry_menu.update(right_hand, left_hand, state_system);
    retry_menu.draw(window);
}

void Game::run_won(GameStateSystem &state_system)
{
    handle_gameplay_events(state_system);

    right_hand.update(cactus, state_system);
    left_hand.update(cactus, state_system);

    render_gameplay_entities();

    win_menu.update(right_hand, left_hand, state_system);
    win_menu.draw(window);
}

void Game::handle_gameplay_events(GameStateSystem &state_system)
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
            } else if (current_event.key.code == sf::Keyboard::O)
            {
                right_hand.grab();
            } else if (current_event.key.code == sf::Keyboard::R)
            {
                state_system.change_state(GameState::Restarting);
            }
        }
    }
}

void Game::render_gameplay_entities()
{
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