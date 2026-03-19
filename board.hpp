#pragma once

#include "disk.hpp"
#include "player.hpp"
#include <iostream>
#include <array>

const int SIZE_BOARD_SIDE = 8;

class Board
{
private:
    std::array<std::array<Disk, SIZE_BOARD_SIDE>, SIZE_BOARD_SIDE> _board;

public:
    Board(/* args */);

    bool is_valid_move(Player player);

    std::array<std::array<Disk, SIZE_BOARD_SIDE>, SIZE_BOARD_SIDE> &get_board() const;



    ~Board() = default;
};
