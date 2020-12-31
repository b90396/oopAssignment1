#pragma once
#include <vector>
#include "EnemyProjectile.h"

using namespace std;
class Enemy
{

public:

	Enemy(int x, int y);
	

	void setYPos();
	int getYPos();
	int getXPos();
	void setXPos();
	bool setIsHit();
	bool getIsHit();
	void setSpeed();
	int getSpeed();
	void move(char direction);	//check position within here with move counter
	void Shoot(vector<EnemyProjectile> &enemyprojectiles);

private:
	int xPos;
	int yPos;
	bool isHit = false;
	int speed = 0;
	int moveCounter = 0;

};

