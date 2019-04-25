#ifndef CACTUS_PICKER_MAINMENU_H
#define CACTUS_PICKER_MAINMENU_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class MainMenu
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

    sf::IntRect play_button_rect;
    sf::IntRect quit_button_rect;

    static const constexpr int BUTTON_WIDTH = 329;
    static const constexpr int BUTTON_HEIGHT = 92;
    static const constexpr int BUTTON_X = 348;
public:
    MainMenu();

    void draw(sf::RenderWindow &window);

    void handle_click(GameStateSystem &state_system, const sf::RenderWindow &window);
};
#endif //CACTUS_PICKER_MAINMENU_H
