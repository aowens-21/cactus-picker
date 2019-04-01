//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_LEFTHAND_H
#define CACTUS_PICKER_LEFTHAND_H

#include "Hand.h"

class LeftHand : public Hand
{
private:
    void process_grab_movement(const sf::FloatRect& cactus_rect) override;
public:
    LeftHand(float x, float y): Hand(x, y, "../images/left_hand.png") {};

    // Handles movement logic
    void update(const sf::FloatRect& cactus_rect);
};

#endif //CACTUS_PICKER_LEFTHAND_H
