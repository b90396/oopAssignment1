#include "Player.h"

Player::Player() : symbol(PLAYER), x(0), y(0), alive(true), escaped(false), dx(0), dy(0)
{
    PositionAtStartingPosition();
}

int Player::GetX()
{
    return x;
}

int Player::GetY()
{
    return y;
}

char Player::GetSymbol() const
{
    return symbol;
}

bool Player::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}

void Player::Move(int key)
{
    switch (key)
    {
    case KEY_LEFT:
        dx = -1;
        dy = 0;
        break;
    case KEY_RIGHT:
        dx = +1;
        dy = 0;
        break;
    case KEY_UP:
        dx = 0;
        dy = -1;
        break;
    case KEY_DOWN:
        dx = 0;
        dy = +1;
        break;
    //case KEY_SPACE:
    //    Shoot();
    //    break;
        //Detected but not registered properly and affects movement, No Idea Why
    default:
        // not a key we care about, so do nothing
        break;
    }

    // update mouse coordinates if move is possible
    if (((x + dx) >= 1) && ((x + dx) <= SIZE) && ((y + dy) >= 1) && ((y + dy) <= SIZE))
    {
        UpdatePosition(dx, dy);
    }
}

void Player::UpdatePosition(int dx, int dy)
{
    x += dx;
    y += dy;
}

void Player::PositionAtStartingPosition()
{
    x = SIZE / 2;
    y = SIZE;
}

void Player::Shoot()
{
    
}

int Player::getScore()
{
    return score;
}

void Player::resetScore()
{
    score = 0;
}

void Player::incrementScore()
{
    score++;
}

int Player::getLives()
{
    return lives;
}

void Player::setLives()
{
    lives = 3;
}

void Player::decreaseLives()
{
    lives--;
}