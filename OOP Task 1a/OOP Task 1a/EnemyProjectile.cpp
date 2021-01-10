#include "EnemyProjectile.h"


/* Simple Inheritance from Projectile class that differentiates how these projectiles interact with the environment.
*  The Enemy Projectiles only move downwards not up the grid, this is incorporated using the Move function called for 
*  all enemy projectiles in the source.cpp.
*  The Encapsulation just returns the value hasHitPlayer or modifies it 
*  (Specific to the enemy projectiles since they are the only projectiles that interact with the player),
*  For use when the game is running.
*/

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
