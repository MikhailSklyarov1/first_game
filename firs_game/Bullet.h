#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>


class Bullet : public Object {

private:
	int damage;
	char direction;

public:	
	Bullet(int da, char di);
	int getBulletDamage() { return damage; }
	char getBulletDirection() { return direction; }

public:
	void bulletFly();
	void bulletVanish();

};
	






