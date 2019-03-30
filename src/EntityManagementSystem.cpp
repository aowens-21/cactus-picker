//
// Created by alex on 3/30/19.
//

#include "../include/EntityManagementSystem.h"

void EntityManagementSystem::register_entity(const Entity &entity)
{
    entity_map.emplace(entity.get_id(), std::make_unique<Entity>(entity));
}