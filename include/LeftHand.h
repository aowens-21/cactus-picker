//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_LEFTHAND_H
#define CACTUS_PICKER_LEFTHAND_H

#include "Hand.h"
#include "Cactus.h"
#include "GameStateSystem.h"

class LeftHand : public Hand
{
private:
    void process_grab_movement(const sf::FloatRect& cactus_rect) override;

    void update_hitbox();
public:
    LeftHand(float x, float y);

    // Handles movement logic
    void update(Cactus &cactus, GameStateSystem& state_system);
};

#endif //CACTUS_PICKER_LEFTHAND_H
