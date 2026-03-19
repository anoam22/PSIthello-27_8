#include "player.hpp"
#include <iostream>


Player::Player(std::string name, DiskColor color)
    : name(name), color(color){};

DiskColor Player::get_color() const
{
    return color;
}

std::string Player::get_name() const
{
    return name;
}