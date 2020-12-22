#pragma once
#include "Projectile.h"
class PlayerProjectile : Projectile
{
public:

	void setHasHitEnemy(bool HHE);
	bool getHasHitEnemy();

private:

	bool hasHitEnemy;



};

