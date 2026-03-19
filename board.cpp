#include "board.hpp"
#include <iostream>

std::vector<int> Board::get_valid_points(Player player)
{
    std::vector<int> legal_points;
    const int size = SIZE_BOARD_SIDE;

    DiskColor color_player = player.get_color();
    DiskColor color_adversary;

    std::array<int, size> x_directions = {0, 1, 1, 1, 0, -1, -1, -1};
    std::array<int, size> y_directions = {1, 1, 0, -1, -1, -1, 0, -1};

    int x_direction = 0;
    int y_direction = 0;

    if (player.get_color() == DiskColor::BLACK)
    {
        color_adversary = DiskColor::WHITE;
    }
    else
    {
        color_adversary = DiskColor::BLACK;
    }

    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size; j++)
        {

            if (!(_board[i][j].get_color() == DiskColor::EMPTY))
            {
                continue;
            }

            for (int k = 0; k < size; k++)
            {

                x_direction = x_directions[k];
                y_direction = y_directions[k];

                if (check_direction(j, i, x_direction, y_direction, color_player, color_adversary))
                {

                    legal_points.push_back(j);
                    legal_points.push_back(i);
                    break;
                }
            }
        }

        x_direction = x_directions[0];
        y_direction = y_directions[0];
    }

    return legal_points;
}

bool Board::check_direction(int x, int y, int direction_x, int direction_y, DiskColor player_color, DiskColor adversary_color)
{
    bool found_adversary_point = false;

    while (true)
    {
        x += direction_x;
        y += direction_y;

        if (x < 0 || x > 7 || y < 0 || y > 7)
        {
            return false;
        }

        if (_board[y][x].get_color() == adversary_color)
        {
            found_adversary_point = true;
        }

        if (_board[y][x].get_color() == player_color && !found_adversary_point || _board[y][x].get_color() == DiskColor::EMPTY)
        {
            return false;
        }
        else if (_board[y][x].get_color() == player_color && found_adversary_point)
        {
            return true;
        }
    }
}

