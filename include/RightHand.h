//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_RIGHTHAND_H
#define CACTUS_PICKER_RIGHTHAND_H

#include "Hand.h"
#include <SFML/Graphics/Sprite.hpp>

class RightHand : public Hand
{
public:
    RightHand(float x, float y): Hand(x, y, "../images/right_hand.png") {};

    void update();
};

#endif //CACTUS_PICKER_RIGHTHAND_H
