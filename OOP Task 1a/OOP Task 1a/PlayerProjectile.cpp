#include "PlayerProjectile.h"

/* Simple Inheritance from Projectile class that differentiates how these projectiles interact with the environment.
*  The player Projectiles only move  up the grid, this is incorporated using the MovePlayerProjectile function called for 
*  all player projectiles in the source.cpp.
*  The Encapsulation just returns the value hasHitEnemy(HHE) or modifies it 
*  (Specific to the player projectiles since they are the only projectiles that interact with the enemies),
*  For use when the game is running.
*/
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