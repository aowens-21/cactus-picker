//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_RIGHTHAND_H
#define CACTUS_PICKER_RIGHTHAND_H

#include "Hand.h"
#include <SFML/Graphics/Sprite.hpp>

class RightHand : public Hand
{
private:
    void process_grab_movement(const sf::FloatRect& cactus_rect) override;
public:
    RightHand(float x, float y): Hand(x, y, "../images/right_hand.png") {};

    void update(const sf::FloatRect& cactus_rect);
};

#endif //CACTUS_PICKER_RIGHTHAND_H
