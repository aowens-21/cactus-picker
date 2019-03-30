#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../include/Game.h"
#include "../include/LeftHand.h"
#include "../include/RightHand.h"
#include "../include/Cactus.h"
#include "../include/EntityManagementSystem.h"

int main()
{
    Game game {};
    GameStateSystem state_system {};

    LeftHand left_hand {game.get_uid()};
    RightHand right_hand {game.get_uid()};
    Cactus cactus {game.get_uid()};

    game.register_entity(left_hand);
    game.register_entity(right_hand);
    game.register_entity(cactus);

    // Start the game loop
    while (game.is_game_running())
    {
        game.run_main_loop(state_system.get_state());
    }

    return EXIT_SUCCESS;
}