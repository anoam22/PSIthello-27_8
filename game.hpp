#pragma once
#include "board.hpp"
#include "disk.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
#include <vector>

class Game
{
private:
    Board _board_instance;
    std::array<Player, 2> _players;
    Player _current_player;

public:
    Game(Board _board_instance);

    void start_game() const;

    /**
     * @brief The function inputs a point from the player
     */
    std::pair<int, int> input_point(Player player);

    /**
     * @brief The function checks if the input is valid
     *
     * @param input The input we are gonna check
     *
     * @returns True if the input is valid False if not
     */
    bool is_valid_input(const std::string &input) const;

    /**
     * @brief The function checks if the move is valid
     *
     * @param point The point we are gonna check
     *
     * @param valid_moves The vector of the current valid
     *                    moves
     *
     * @returns True if the point is in the vector of
     *          the valid moves
     */
    bool is_valid_move(std::pair<int, int> point, const std::vector<int> &valid_moves);

    /**
     * @brief The function takes a string and converts it into
     *        a pair (point).
     *        Example:
     *        D3 ------> (3,2)
     *
     * @param input The string we convert
     *
     * @returns The pair (point) we converted into
     */
    std::pair<int, int> convert_to_cords(const std::string &input);

    /**
     * @brief The functino prints the board
     */
    void print_board();

    /**
     * @brief The functino get the new point, conqure the disks, and update the board
     */
    void update_board();

    /**
     * @brief The function checks a direction, it saves the vector of the disks that needed to be changed
     *
     * @param x The current x of the checking slot
     * @param y The current y of the checking slot
     * @param direction_x The direction to go in the X axis. 0 means none, 1 right -1 left
     * @param direction_y The direction to go in the y axis. 0 means none, 1 up -1 down
     * @param player_color The player's disk color
     * @param adversary_color The adversary's disk color
     *
     */
    void update_disks_by_direction(int x, int y, int direction_x, int direction_y, DiskColor player_color, DiskColor adversary_color);

    /**
     * @brief The function checks the locations in the vector and set the variables color
     *
     * @param disks_to_change Vecotor of locations to change
     * @param player_color The player color
     *
     */
    void change_disks(std::vector<std::pair<int, int>> disks_to_change, DiskColor player_color);

    void set_board(Board board);

    void end_game() const;

    void switch_player();

    Player &get_winner() const;

    std::array<std::array<Disk, SIZE_BOARD_SIDE>, SIZE_BOARD_SIDE> get_board() const;

    ~Game() = default;
};

/**
 * @return The functino return the char by the menue
 */
char get_char_by_enum(DiskColor disk_color);
