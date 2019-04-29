//
// Created by alex on 4/25/19.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "../include/GameStateSystem.h"
#include "../include/MainMenu.h"

MainMenu::MainMenu()
{
    // Set up rendering attributes
    texture.loadFromFile("../images/main_menu.png");
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
}

void MainMenu::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void MainMenu::update(GameStateSystem &state_system)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        state_system.change_state(GameState::Restarting);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        state_system.change_state(GameState::Exiting);
    }
}