#include "PlayerProjectile.h"

void PlayerProjectile::setHasHitEnemy(bool HHE)
{
	hasHitEnemy = HHE;
}

bool PlayerProjectile::getHasHitEnemy()
{
	return hasHitEnemy;
}

void PlayerProjectile::movePlayerProjectile()
{
	setYPos(getYPos() - 1);
}