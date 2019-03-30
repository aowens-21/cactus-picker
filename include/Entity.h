//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_ENTITY_H
#define CACTUS_PICKER_ENTITY_H

class Entity
{
private:
    unsigned long id;
public:
    explicit Entity(unsigned long uuid): id{uuid} {};
};

#endif //CACTUS_PICKER_ENTITY_H
