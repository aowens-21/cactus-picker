#include "EffectSystem.h"

EffectSystem::EffectSystem()
{
    // Load textures
    pluck_effect_texture.loadFromFile("../images/pluck_effect.png");
}

void EffectSystem::play_pluck_effect(float x, float y)
{
    play_effect(EffectType::Pluck, x, y);
}

void EffectSystem::draw(sf::RenderWindow &window)
{
    for (auto& effect : effects) {
        window.draw(effect.sprite);
    }
}

void EffectSystem::update()
{
    // Cleanup all effects that need to be gone
    cleanup_effects();
}

void EffectSystem::cleanup_effects()
{
    effects.erase(std::remove_if(effects.begin(), effects.end(), [this](Effect &effect)
    {
        return (clock.getElapsedTime() >= effect.duration + effect.create_time);
    }), effects.end());
}

void EffectSystem::reset_effects()
{
    effects.erase(effects.begin(), effects.end());
}

void EffectSystem::play_effect(EffectType &&type, float x, float y)
{
    auto effect = Effect();
    auto sprite = sf::Sprite();

    if (type == EffectType::Pluck) {
        sprite.setTexture(pluck_effect_texture);
        effect.duration = sf::milliseconds(100);
    }

    sprite.setPosition(x, y);
    effect.sprite = sprite;
    effect.create_time = clock.getElapsedTime();

    effects.emplace_back(effect);
}