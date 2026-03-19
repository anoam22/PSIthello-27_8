#include "game.hpp"
#include <iostream>
#include <limits>

std::pair<int, int> Game::input_point(Player player)
{
    std::string input;

    while (true)
    {
        std::cout << "Enter a point (like D3): ";
        std::cin >> input;

        if (is_valid_input(input))
        {
            std::pair<int, int> point = convert_to_cords(input);

            if (is_valid_move(point, _board_instance.get_valid_points(player)))
            {
                return point;
            }

            else
            {
                std::cout << "Invalid move!" << std::endl;
                std::cout << "Press Enter to continue...";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
            }
        }
    }
}
bool Game::is_valid_input(const std::string &input) const
{
    if (input.length() != 2)
        return false;

    char col = toupper(input[0]);
    if (col < 'A' || col > 'H')
        return false;

    char row = input[1];
    if (row < '1' || row > '8')
        return false;

    return true;
}

std::pair<int, int> Game::convert_to_cords(const std::string &input)
{
    int x = toupper(input[0]) - 'A';
    int y = input[1] - '1';
    return {x, y};
}

bool Game::is_valid_move(std::pair<int, int> point, const std::vector<int> &valid_moves)
{
    for (int i = 0; i + 1 < valid_moves.size(); i += 2)
    {
        int x = valid_moves[i];
        int y = valid_moves[i + 1];
        if (point.first == x && point.second == y)
        {
            return true;
        }
    }
    return false;
}

char get_char_by_enum(DiskColor disk_color)
{

    switch (disk_color)
    {
    case DiskColor::BLACK:
        return 'O';
    case DiskColor::WHITE:
        return 'X';
    case DiskColor::EMPTY:
        return '-';
    default:
        break;
    }
}

void Game::print_board()
{
    int size = SIZE_BOARD_SIDE;
    std::vector<int> points = _board_instance.get_valid_points(_current_player);
    std::pair<int, int> point;

    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size; j++)
        {
            point.first = j;
            point.second = i;

            if (is_valid_move(point, points))
            {
                std::cout << "* ";
            }
            else
            {
                std::cout << get_char_by_enum(_board_instance._board[i][j].get_color()) << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Game::update_board()
{
    std::pair<int, int> input_disk = input_point(_current_player);
    DiskColor color_adversary;
    const int size = SIZE_BOARD_SIDE;

    if (_current_player.get_color() == DiskColor::BLACK)
    {
        color_adversary = DiskColor::WHITE;
    }
    else
    {
        color_adversary = DiskColor::BLACK;
    }

    std::array<int, size> x_directions = {0, 1, 1, 1, 0, -1, -1, -1};
    std::array<int, size> y_directions = {1, 1, 0, -1, -1, -1, 0, -1};


}