#pragma once
class Projectile
{
private:
	// Attributes.
	float speed;
	int x;
	int y;
	bool hasHitBarrier;
	bool hasHitProjectile;
public:
	// Constructors.
	Projectile();
	Projectile(int x, int y, float speed);
	~Projectile() {};

	// Accessor methods.
	int getXPos() const;
	int getYPos() const;
	float getSpeed() const;
	bool getHasHitBarrier() const;
	bool getHasHitProjectile() const;

	// Mutator Methods.
	int setXPos( int x );
	int setYPos( int y );
	float setSpeed( float speed );
	void setHasHitBarrier( bool value );
	void setHasHitProjectile( bool value );

	void updatePosition();
	void hitBarrier();
};

