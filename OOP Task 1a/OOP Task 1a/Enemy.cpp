#include "Enemy.h"
#include <vector>
#include "Game.h"
#include "EnemyProjectile.h"
Enemy::Enemy(int x, int y)
{

	xPos = x;
	yPos = y;

}

void Enemy::setYPos()
{

}

int Enemy::getYPos()
{
	return yPos;
}

int Enemy::getXPos()
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
		moveCounter = 0;
	}

	if (direction == 'R')
	{
		xPos += 1;
		moveCounter = 0;
	}

	if (direction == 'D' && moveCounter == 0)
	{
		yPos += 1;
		moveCounter = 1;
	}
	else if(moveCounter == 1)
	{
		xPos += 1;
		moveCounter == 0;
	}
}

void Enemy::Shoot(vector<EnemyProjectile> &enemyprojectile)
{
	enemyprojectile.push_back(EnemyProjectile(getXPos(), (getYPos() + 1), 1));
}
