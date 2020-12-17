#pragma once
#include "Projectile.h"
class PlayerProjectile : Projectile
{
public:

	void setHasHitEnemy();
	bool getHasHitEnemy();

private:

	bool hasHitEnemy();



};

