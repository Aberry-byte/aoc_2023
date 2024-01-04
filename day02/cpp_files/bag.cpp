#include "bag.hpp"

Bag::Bag(int num_of_red, int num_of_green, int num_of_blue)
{
    this->red = num_of_red;
    this->green = num_of_green;
    this->blue = num_of_blue;
}

Bag::~Bag()
{
}

bool Bag::valid_pull(int num_of_red, int num_of_green, int num_of_blue)
{
    if (num_of_red > this->red)
    {
        return false;
    }
    else if (num_of_green > this->green)
    {
        return false;
    }
    else if (num_of_blue > this->blue)
    {
        return false;
    }
    return true;
}