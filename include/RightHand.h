//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_RIGHTHAND_H
#define CACTUS_PICKER_RIGHTHAND_H

#include "Hand.h"
#include "Cactus.h"
#include "GameStateSystem.h"
#include <SFML/Graphics/Sprite.hpp>

class RightHand : public Hand
{
private:
    void process_grab_movement(const sf::FloatRect& cactus_rect) override;

    void update_hitbox();
public:
    RightHand(float x, float y);

    void update(Cactus &cactus, GameStateSystem& state_system);
};

#endif //CACTUS_PICKER_RIGHTHAND_H
