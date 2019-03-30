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

    LeftHand left_hand {};
    RightHand right_hand {};
    Cactus cactus {};

    // Start the game loop
    while (game.is_game_running())
    {
        game.run_main_loop(state_system.get_state());
    }

    return EXIT_SUCCESS;
}