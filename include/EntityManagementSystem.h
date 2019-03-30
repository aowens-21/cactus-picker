//
// Created by alex on 3/30/19.
//

#ifndef CACTUS_PICKER_ENTITYMANAGEMENTSYSTEM_H
#define CACTUS_PICKER_ENTITYMANAGEMENTSYSTEM_H

#include "Entity.h"
#include <map>
#include <memory>

class UniqueIdentifierGenerator
{
private:
    unsigned long current_id = 0;
public:
    UniqueIdentifierGenerator()=default;

    unsigned long get_uid();
};

unsigned long UniqueIdentifierGenerator::get_uid()
{
    auto id = current_id;
    current_id++;
    return id;
}

class EntityManagementSystem
{
private:
    // To register ids
    UniqueIdentifierGenerator uid_generator {};

    // Map of ids to pointers to entities
    std::map<unsigned long, std::unique_ptr<Entity>> entity_map;
public:
    EntityManagementSystem()=default;

    // Adds the entity to the map
    void register_entity(const Entity& entity);

    // Gets a uid for a new entity
    unsigned long get_id() { return uid_generator.get_uid(); }
};

#endif //CACTUS_PICKER_ENTITYMANAGEMENTSYSTEM_H
