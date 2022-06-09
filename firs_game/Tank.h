#pragma once
#include<vector>
#include "Object.h"
#include "Bullet.h"
#include <SFML/Graphics.hpp>


class Tank : public Object {

private:
	int health;
	int damage;
	char direction;
	int fireController;
	
public:
	void setDamage(int da) { damage = da; }
	void setHealth(int he) { health = he; }
	void setDirection(char di) { direction = di; }
	void setFireController(int fi) { fireController = fi; }
	void controllerAdd() { fireController++; }

public:
	int getHealth() { return health; }
	int getDamage() { return damage; }
	int getFireController() { return fireController; }
	char getDirection() { return direction; }
	
public:
	void tankMove();
	void tankFire();
	void tankAction();
	Tank(int heal, int da, char di, int fi);

};

