#include "disk.hpp"

Disk::Disk()
{
    color = DiskColor::EMPTY;
}

void Disk::set_color(DiskColor new_color)
{
    color = new_color;
}

DiskColor Disk::get_color() const
{
    return color;
}