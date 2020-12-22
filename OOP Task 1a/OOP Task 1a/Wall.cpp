#include "Wall.h"

Wall::Wall()
{
    symbol = WALL;
}

Wall::Wall(int x, int y)
{
    symbol = WALL;
    this->x = x;
    this->y = y;
}

bool Wall::IsAtPosition(int x, int y)
{
    return (this->x == x) && (this->y == y);
}

int Wall::GetX() const
{
    return x;
}

int Wall::GetY() const
{
    return y;
}

char Wall::GetSymbol() const
{
    return symbol;
}