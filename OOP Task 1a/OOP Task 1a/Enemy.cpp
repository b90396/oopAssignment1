#include "Enemy.h"

Enemy::Enemy(int x, int y)
{

	xPos = x;
	yPos = y;

}

void Enemy::setYPos()
{

}

int Enemy::getYPos() const
{
	return yPos;
}

int Enemy::getXPos() const
{
	return xPos;
}

void Enemy::setXPos()
{
	
}

bool Enemy::setIsHit()
{
	if (isHit)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Enemy::getIsHit()
{
	return true;
}

void Enemy::setSpeed()
{
	// Get X & Y Pos, increase speed at set points e.g: half of board = speed X2 , etc
}

int Enemy::getSpeed()
{
	return speed;
}

void Enemy::move()
{
	// While Player::isAlive xpos +/- 1 every x seconds (by speed) if xpos == end of grid
	// ypos +/- 1 then xpos +/- 1.
}
