//
// Created by alex on 4/25/19.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include "../include/GameStateSystem.h"
#include "../include/MainMenu.h"

MainMenu::MainMenu()
{
    // Set up rendering attributes
    texture.loadFromFile("../images/main_menu.png");
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);

    // Set up button rects
    play_button_rect.left = BUTTON_X;
    play_button_rect.top = 368;
    play_button_rect.width = BUTTON_WIDTH;
    play_button_rect.height = BUTTON_HEIGHT;

    quit_button_rect.left = BUTTON_X;
    quit_button_rect.top = 538;
    quit_button_rect.width = BUTTON_WIDTH;
    quit_button_rect.height = BUTTON_HEIGHT;
}

void MainMenu::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void MainMenu::handle_click(GameStateSystem &state_system, const sf::RenderWindow &window)
{
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

    if (play_button_rect.contains(mouse_pos)) {
        state_system.change_state(GameState::Restarting);
    } else if (quit_button_rect.contains(mouse_pos)) {
        state_system.change_state(GameState::Exiting);
    }
}