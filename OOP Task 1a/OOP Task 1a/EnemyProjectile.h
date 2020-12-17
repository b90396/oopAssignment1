#pragma once
#include "Projectile.h"
class EnemyProjectile : Projectile
{

public:
	void setHasHitPlayer();
	bool getHasHitPlayer();

private:

	bool hasHitPlayer();

};

