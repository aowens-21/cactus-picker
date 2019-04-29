#ifndef CACTUS_PICKER_MAINMENU_H
#define CACTUS_PICKER_MAINMENU_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class MainMenu
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    MainMenu();

    void draw(sf::RenderWindow &window);

    void update(GameStateSystem &state_system);
};
#endif //CACTUS_PICKER_MAINMENU_H
