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

void Enemy::move(char direction)
{
	if (direction == 'L')
	{
		xPos -= 1;
	}

	if (direction == 'R')
	{
		xPos += 1;
	}

	if (direction == 'D')
	{
		yPos += 1;
	}
}
