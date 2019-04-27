#ifndef CACTUS_PICKER_GAME_H
#define CACTUS_PICKER_GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "GameStateSystem.h"
#include "RightHand.h"
#include "Cactus.h"
#include "LeftHand.h"
#include "RetryMenu.h"
#include "MainMenu.h"

constexpr const float INIT_HAND_Y = 670;
constexpr const float INIT_LEFT_HAND_X = 0;
constexpr const float INIT_RIGHT_HAND_X = 900;
constexpr const float INIT_CACTUS_X = 380;
constexpr const float INIT_CACTUS_Y = 55;
constexpr const int WINDOW_WIDTH = 1024;
constexpr const int WINDOW_HEIGHT = 800;

// Singleton to represent the game as a whole, managing the actors and game state
class Game
{
private:
    // Game will have control over the window
    sf::RenderWindow window {sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Cactus Picker"};

    // Game's background image
    sf::Texture bg_texture;
    sf::Sprite bg_sprite;

    // Controls textures
    sf::Texture q_texture;
    sf::Sprite q_sprite;
    sf::Texture w_texture;
    sf::Sprite w_sprite;
    sf::Texture p_texture;
    sf::Sprite p_sprite;
    sf::Texture o_texture;
    sf::Sprite o_sprite;

    // For event polling
    sf::Event current_event;

    // Keeping track of if the game is still running
    bool is_running = true;

    // Menu members
    RetryMenu retry_menu = RetryMenu();
    MainMenu main_menu = MainMenu();

    // All of the main game members
    RightHand right_hand = RightHand(INIT_RIGHT_HAND_X, INIT_HAND_Y);
    LeftHand left_hand = LeftHand(INIT_LEFT_HAND_X, INIT_HAND_Y);
    Cactus cactus = Cactus(INIT_CACTUS_X, INIT_CACTUS_Y);

    // Clock for the timer
    sf::Clock clock;
    sf::Font game_font;

    // Time as a string
    sf::Text time_display;
    sf::Texture timer_bg_texture;
    sf::Sprite timer_bg_sprite;

    void update_time();

    void init_time_display();

    void run_playing(GameStateSystem &state_system);

    void run_main_menu(GameStateSystem &state_system);

    void run_restarting(GameStateSystem &state_system);

    void run_exiting();

    void run_lost(GameStateSystem &state_system);

    void run_won(GameStateSystem &state_system);
public:
    Game();

    // Tells main if the game is still running
    bool is_game_running() const noexcept { return is_running; }

    // Runs main loop based on the game state system
    void run_main_loop(GameStateSystem& state_system);

    void start_game();

    void render_gameplay_entities();

    void handle_gameplay_events(GameStateSystem &state_system);
};

#endif //CACTUS_PICKER_GAME_H
