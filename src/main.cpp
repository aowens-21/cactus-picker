#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../include/Game.h"
#include "../include/LeftHand.h"
#include "../include/RightHand.h"
#include "../include/Cactus.h"

int main()
{
    Game game {};
    GameStateSystem state_system {};

    // Start the game loop
    while (game.is_game_running())
    {
        game.run_main_loop(state_system);
    }

    return EXIT_SUCCESS;
}