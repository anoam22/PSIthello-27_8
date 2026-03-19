#include "board.hpp"
#include <iostream>

bool Board::is_valid_move(Player player)
{
    std::vector<int> valid_moves = get_valid_points(player);
    
}