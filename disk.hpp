#pragma once

class Disk
{
private:
    DiskColor color;

public:
    Disk();

    void set_color(DiskColor new_color);

    DiskColor get_color() const;

    ~Disk() = default;
};

