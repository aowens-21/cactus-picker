//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_GAMESTATESYSTEM_H
#define CACTUS_PICKER_GAMESTATESYSTEM_H

// Each one controls a different main game loop
enum class GameState { MainMenu, Settings, Playing, GameWon, GameLost };

class GameStateSystem
{
private:
    GameState current_state;
public:
    // Initialize to some beginning state
    GameStateSystem(): current_state{GameState::MainMenu} {};

    // Get the state for use by Game object
    GameState get_state() const noexcept { return current_state; }

    // Change the state
    void change_state(const GameState& new_state) { current_state = new_state; }
};

#endif //CACTUS_PICKER_GAMESTATESYSTEM_H
