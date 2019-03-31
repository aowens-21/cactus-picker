//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_LEFTHAND_H
#define CACTUS_PICKER_LEFTHAND_H

#include "Hand.h"

class LeftHand : public Hand
{
public:
    LeftHand(float x, float y): Hand(x, y, "../images/left_hand.png") {};
};

#endif //CACTUS_PICKER_LEFTHAND_H
