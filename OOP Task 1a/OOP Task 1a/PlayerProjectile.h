#pragma once
#include "Projectile.h"
/* Player Projectile Header File Inherits from the projectile class in the same way as the enemy projectile class,
*  It uses the constructors from the projectile class (using) and 3 public functions, 2 that set and return the value 
*  when an enemy is hit (specific to the player projectile) and one that moves the projectile up the screen since the player projectile
*  moves up not down.
*  The Private variable is for when the projectile hits an enemy and both functions encapsulate this value.
*/
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

