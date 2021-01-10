#include "Enemy.h"
#include <vector>
#include "Game.h"
#include "EnemyProjectile.h"

/* Enemy Class .cpp File
	Features a Constructor to build all enemies and plot their X & Y Positions within the grid.
	Encapsulation is used to return the X & Y values so that they can be drawn, and also manages the movement system for the enemies.
	No other files can modify the X & Y values of each enemy and all functions are called through either Source or Game files.
	A vector is used to store all the projectiles the enemies shoot which is passed by reference so that it can be modified
	this then allows us to add new projectiles at that enemies X & Y coordinates.
	The Methods also allow, through encapsulation. To check if the enemy has been hit and set if they have been hit when the method is
	called in game.cpp.
*/


Enemy::Enemy(int x, int y)
	: xPos(x), yPos(y)
{}

int Enemy::getYPos()
{
	return yPos;
}

int Enemy::getXPos()
{
	return xPos;
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
