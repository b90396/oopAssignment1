#pragma once
#include "Projectile.h"
class PlayerProjectile : Projectile
{
public:

	void setHasHitEnemy(bool HHE);
	bool getHasHitEnemy();
	using Projectile::Projectile;

private:
	bool hasHitEnemy;

};

