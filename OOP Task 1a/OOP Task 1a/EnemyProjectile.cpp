#include "EnemyProjectile.h"

void EnemyProjectile::setHasHitPlayer()
{
	hasHitPlayer = true;
}

bool EnemyProjectile::getHasHitPlayer()
{
	return hasHitPlayer;
}

void EnemyProjectile::move()
{
	setYPos(getYPos() + 1);
}
