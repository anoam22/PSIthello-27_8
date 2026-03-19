#include "game.hpp"
#include <iostream>
#include <limits>


Game::Game(Board _board_instance)
    : _board_instance(_board_instance),
      _players{ Player("Black", DiskColor::BLACK),
                Player("White", DiskColor::WHITE) },
      _current_player(_players[0])
{
}

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
        return '-';
    }
    return 'F';
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

void Game::set_board(Board board)
{
    this->_board_instance = board;
}


void Game::update_board()
{
    std::pair<int, int> input_disk = input_point(_current_player);
    DiskColor color_adversary;
    DiskColor color_player = _current_player.get_color();

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

    int x_direction = 0;
    int y_direction = 0;

    int x_input = input_disk.first;
    int y_input = input_disk.second;

    for (int i = 0; i < size; i++)
    {
        x_direction = x_directions[i];
        y_direction = y_directions[i];

        update_disks_by_direction(x_input, y_input, x_direction, y_direction, color_player, color_adversary);
    }

    _board_instance.get_board()[y_input][x_input].set_color(color_player);
}

void Game::update_disks_by_direction(int x, int y, int direction_x, int direction_y, DiskColor player_color, DiskColor adversary_color)
{
    bool found_adversary_point = false;
    std::vector<std::pair<int, int>> disks_to_change;
    std::pair<int, int> current_point;

    while (true)
    {
        x += direction_x;
        y += direction_y;

        current_point.first = x;
        current_point.second = y;

        disks_to_change.push_back(current_point);

        if (x < 0 || x > 7 || y < 0 || y > 7)
        {
            break;
        }

        if (_board_instance.get_board()[y][x].get_color() == adversary_color)
        {
            found_adversary_point = true;
        }

        if (_board_instance.get_board()[y][x].get_color() == player_color && !found_adversary_point || _board_instance.get_board()[y][x].get_color() == DiskColor::EMPTY)
        {
            break;
        }
        else if (_board_instance.get_board()[y][x].get_color() == player_color && found_adversary_point)
        {
            change_disks(disks_to_change, player_color);
            break;
        }
    }
}

void Game::change_disks(std::vector<std::pair<int, int>> disks_to_change, DiskColor player_color)
{

    int x;
    int y;

    for (auto pair : disks_to_change)
    {
        x = pair.first;
        y = pair.second;

        _board_instance.get_board()[y][x].set_color(player_color);
    }
}
