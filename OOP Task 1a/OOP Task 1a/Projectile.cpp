#include "Projectile.h"

Projectile::Projectile()
{
	x = y = speed = 0;
	hasHitBarrier = hasHitProjectile = false;
}

Projectile::Projectile(int x, int y, float speed)
{
	this->x = x;
	this->y = y;
	this->speed = speed;
	hasHitBarrier = hasHitProjectile = false;
}

// Accessor methods.
int Projectile::getXPos() const
{
	return x;
}

int Projectile::getYPos() const
{
	return y;
}

float Projectile::getSpeed() const
{
	return speed;
}

bool Projectile::getHasHitBarrier() const
{
	// to-do.
	return false;
}

bool Projectile::getHasHitProjectile() const
{
	// to-do.
	return false;
}

// Mutator Methods.
int Projectile::setXPos(int x)
{
	this->x = x;
}

int Projectile::setYPos(int y)
{
	this->y = y;
}

float Projectile::setSpeed(float speed)
{
	this->speed = speed;
}

void Projectile::setHasHitBarrier(bool value)
{
	hasHitBarrier = value;
}

void Projectile::setHasHitProjectile(bool value)
{
	hasHitProjectile = value;
}

void Projectile::updatePosition()
{
	// to-do.
}

void Projectile::hitBarrier()
{
	hasHitBarrier = true;
}