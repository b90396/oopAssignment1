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

void Enemy::Shoot(vector<EnemyProjectile> &enemyprojectile)
{
	enemyprojectile.push_back(EnemyProjectile(getXPos(), (getYPos() + 1), 1));
}
