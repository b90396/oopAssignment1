#include "PlayerProjectile.h"

void PlayerProjectile::setHasHitEnemy(bool HHE)
{
	hasHitEnemy = HHE;
}

bool PlayerProjectile::getHasHitEnemy()
{
	return hasHitEnemy;
}
