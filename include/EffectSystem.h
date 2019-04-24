#ifndef CACTUS_PICKER_EFFECTSYSTEM_H
#define CACTUS_PICKER_EFFECTSYSTEM_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

struct Effect
{
    sf::Sprite sprite;
    sf::Time create_time;
    sf::Time duration;
};

enum class EffectType { Poke, Pluck };

class EffectSystem
{
private:
    sf::Clock clock;

    sf::Texture pluck_effect_texture;
    sf::Texture poked_effect_texture;

    std::vector<Effect> effects;

    void cleanup_effects();

    void play_effect(EffectType &&type, float x, float y);
public:
    EffectSystem();

    void draw(sf::RenderWindow &window);

    void update();

    void play_pluck_effect(float x, float y);

    void reset_effects();
};


#endif //CACTUS_PICKER_EFFECTSYSTEM_H
