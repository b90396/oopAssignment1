#pragma once
class Enemy
{

public:

	Enemy(int x, int y);
	

	void setYPos();
	int getYPos() const;
	int getXPos() const;
	void setXPos();
	void setIsHit();
	bool getIsHit();
	void setSpeed();
	int getSpeed();
	void move();	//check position within here with move counter

private:
	int xPos;
	int yPos;
	bool isHit;
	int speed;
	int moveCounter;

};

