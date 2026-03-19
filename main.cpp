#include "game.hpp"
#include "disk.hpp"
#include "board.hpp"
#include "disk_color.hpp"
#include <iostream>

int main()
{
    
    std::array<std::array<Disk, SIZE_BOARD_SIDE>, SIZE_BOARD_SIDE> board;
    Board board_inter(board);
    Game game(board);
    game.print_board();

}