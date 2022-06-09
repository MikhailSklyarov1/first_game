#pragma once
#include "Bullet.h"
#include<vector>
#include "Object.h"
#include <SFML/Graphics.hpp>

class Enemy : public Object {

private:
	int health;
	int damage;
	char direction;
	int bulletControll;

public:
	void setHealth(int heal) { health = heal; }
	void setBulletControll(int n) { bulletControll = n; }
	void ControllerAdd() { bulletControll++; }		
	
public:
	char getDirection() { return direction; }
	int getDamage() { return damage; }
	int getHealth() { return health; }
	int getBulletControll() { return bulletControll; }

public:
	void enemyMove();
	void enemyFire();
	void enemyAction();
	Enemy(int heal, int da, char di, int fi);

};