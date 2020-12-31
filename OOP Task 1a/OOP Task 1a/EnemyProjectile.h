#pragma once
#include "Projectile.h"
class EnemyProjectile : Projectile
{
public:
	void setHasHitPlayer();
	bool getHasHitPlayer();
	using Projectile::Projectile;
private:

	bool hasHitPlayer;

};

