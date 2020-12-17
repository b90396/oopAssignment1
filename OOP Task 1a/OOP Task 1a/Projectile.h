#pragma once
class Projectile
{

public:

	float getSpeed();
	float setSpeed();

	int getXPos();
	int setXPos();
	int getYPos();
	int setYPos();

	void setHasHitBarrier();
	void setHasHitProjectile();

	bool getHasHitBarrier();
	bool getHasHitProjectile();

	void updatePosition();
	void hitBarrier();


private:

	float speed;
	int xpos;
	int ypos;
	bool hasHitBarrier;
	bool hasHitProjectile;


};

