#pragma once

#include "disk_color.hpp"

/**
 * Represents Disk
 */
class Disk
{
private:
    DiskColor color;

public:
    /**
     * @brief The constructor of disk
     */
    Disk();

    /**
     * @brief Set a new color to a disk
     *
     * @param new_color The new color of the disk
     */
    void set_color(DiskColor new_color);

    /**
     * @brief Get the color of the disk
     *
     * @return Returning an enum of the color
     */
    DiskColor get_color() const;

    ~Disk() = default;
};
