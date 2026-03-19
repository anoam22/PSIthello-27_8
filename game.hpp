#pragma once
#include "board.hpp"
#include "disk.hpp"
#include <iostream>


class Game
{
private:
    Board _board_instance;
    std::array<Player> _players;
    Player _current_player;

public:
    Game(/* args */);

    void start_game() const;

    void end_game() const;

    void switch_player();

    Player &get_winner() const;

    std::array<std::array<Disk, SIZE_BOARD_SIDE>, SIZE_BOARD_SIDE> get_board() const;

    ~Game();
};
