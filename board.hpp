#pragma once

#include "disk.hpp"
#include "player.hpp"
#include <iostream>
#include <array>
#include <vector>

const int SIZE_BOARD_SIDE = 8;

/**
 * Represents board
 */
class Board
{
private:
    std::array<std::array<Disk, SIZE_BOARD_SIDE>, SIZE_BOARD_SIDE> _board;

public:
    /**
     * @brief The constructor of board
     */
    Board(/* args */);

    /**
     * @brief The function returns the locations that are valid to the user to put disks
     *
     * @param player The current player that is playing
     */
    std::vector<int> get_valid_points(Player player);

    /**
     * @brief The function returns the locations that are valid to the user to put disks
     *
     * @param x The current x of the checking slot
     * @param y The current y of the checking slot
     * @param direction_x The direction to go in the X axis. 0 means none, 1 right -1 left
     * @param direction_y The direction to go in the y axis. 0 means none, 1 up -1 down
     * @param player_color The player's disk color
     * @param adversary_color The adversary's disk color
     */
    bool check_direction(int x, int y, int direction_x, int direction_y, DiskColor player_color, DiskColor adversary_color);

    bool is_valid_move(Player player);

    std::array<std::array<Disk, SIZE_BOARD_SIDE>, SIZE_BOARD_SIDE> &get_board() const;

    ~Board() = default;
};
