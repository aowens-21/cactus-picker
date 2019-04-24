//
// Created by aowens on 4/22/19.
//

#ifndef CACTUS_PICKER_MENU_H
#define CACTUS_PICKER_MENU_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "RightHand.h"
#include "LeftHand.h"
#include "GameStateSystem.h"

const constexpr float BUTTON_WIDTH = 19.0;
const constexpr float BUTTON_HEIGHT = 27.0;

class RetryMenu {
private:
    sf::Texture menu_texture;
    sf::Sprite menu_sprite;

    sf::FloatRect retry_rect;
    sf::FloatRect quit_rect;
public:
    RetryMenu();

    void draw(sf::RenderWindow& window);

    void update(const RightHand& rh, const LeftHand& lh, GameStateSystem& state_system);
};

#endif //CACTUS_PICKER_MENU_H