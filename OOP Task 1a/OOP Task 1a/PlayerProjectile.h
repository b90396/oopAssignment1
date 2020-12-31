#pragma once
#include "Projectile.h"
class PlayerProjectile : public Projectile
{
public:

	void setHasHitEnemy(bool HHE);
	bool getHasHitEnemy();
	void movePlayerProjectile();
	using Projectile::Projectile;

private:
	bool hasHitEnemy;
};

