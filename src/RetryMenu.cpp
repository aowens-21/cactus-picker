//
// Created by aowens on 4/22/19.
//

#include "../include/RetryMenu.h"

RetryMenu::RetryMenu()
{
    menu_texture.loadFromFile("../images/retry_menu.png");
    menu_sprite.setTexture(menu_texture);
    menu_sprite.setPosition(250, 200);

    retry_rect.left = menu_sprite.getPosition().x;
    retry_rect.top = menu_sprite.getPosition().y + 194;
    retry_rect.width = BUTTON_WIDTH;
    retry_rect.height = BUTTON_HEIGHT;

    quit_rect.left = menu_sprite.getPosition().x + menu_sprite.getTexture()->getSize().x - BUTTON_WIDTH;
    quit_rect.top = menu_sprite.getPosition().y + 315;
    quit_rect.width = BUTTON_WIDTH;
    quit_rect.height = BUTTON_HEIGHT;
}

void RetryMenu::draw(sf::RenderWindow& window)
{
    window.draw(menu_sprite);
}

void RetryMenu::update(const RightHand& rh, const LeftHand& lh, GameStateSystem& state_system)
{
    bool exit = quit_rect.intersects(rh.get_rect()) || quit_rect.intersects(lh.get_rect());

    bool restart = retry_rect.intersects(rh.get_rect()) || retry_rect.intersects(lh.get_rect());

    if (exit)
    {
        state_system.change_state(GameState::Exiting);
    }
    else if (restart)
    {
        state_system.change_state(GameState::Restarting);
    }
}

