#pragma once
#include "Projectile.h"

/* Header File for the enemy projectiles, Inherits from the projectiles class
* to work the projectile contstructor properly, the files incorporates "using" the default and set contructors
* used in the Projectile class.
* Includes all public methods to be accessed in the Game and Source files and the private variable used in the projectile classes
*/
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
