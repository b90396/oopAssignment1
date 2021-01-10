#pragma once
#include <vector>
#include "EnemyProjectile.h"

/* Header File for Enemy Class, Stores the private variables for the X and Y position of the enemy on the grid.
*  Also Stores the ishit variable that checks if the enemy has been hit and is modified in the relevant functions.
*  Includes the direction of the enemy using a move counter.
*  All public encapsulation functions are also included in the header file.
*/

using namespace std;
class Enemy
{

public:

	Enemy(int x, int y);
	
	int getYPos();
	int getXPos();
	bool setIsHit();
	bool getIsHit();
	void move(char direction);	//check position within here with move counter
	void Shoot(vector<EnemyProjectile> &enemyprojectiles);

private:
	int xPos;
	int yPos;
	bool isHit = false;
	int moveCounter = 0;

};

