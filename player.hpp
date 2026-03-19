#pragma once

#include <string>
#include "disk_color.hpp"

/**
 * @class Player
 *
 * @brief Represents a player.
 */
class Player {
private:
    std::string name;
    DiskColor color;

public:
    /**
     * @brief Gets the name of the player
     * 
     * @returns The player's name
     */
    std::string get_name() const;

    /**
     * @brief Gets the color of the player
     * 
     * @returns The player's color
     */
    DiskColor get_color() const;
};