#pragma once
#include "Projectile.h"
class EnemyProjectile : public Projectile
{
public:
	void setHasHitPlayer();
	bool getHasHitPlayer();
	void move();
	using Projectile::Projectile;

private:

	bool hasHitPlayer;

};
