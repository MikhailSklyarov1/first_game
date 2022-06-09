#include "Enemy.h"
#include "Bullet.h"
#include "Universe.h"
#include <math.h>
#include "Define.h"
#include <vector>
#include <time.h>
#include <iostream>
#include <SFML/Graphics.hpp>
extern Tank  tank;

void Enemy::enemyFire() {
	sf::Vector2f myPosition = tank.getPosition();
	if (abs(getPosition().x - myPosition.x) < 50 || abs(getPosition().y - myPosition.y) < 50) {
		
		if (getBulletControll() % 30 == 0) {
			Bullet bullet = Bullet(getDamage(), getDirection());
			bullet.setOrigin(10, 10);
			bullet.setPosition(getPosition());
			bullet.setRotation(getRotation());
			bullet.setObstacleSpeed(BulletSpeed);
			Universe::EnmeyBulletBuf.push_back(bullet);		
		}
		ControllerAdd();
	}
}

void Enemy::enemyAction() {
	enemyMove();
	enemyFire();
}

void Enemy::enemyMove() {
	
	sf::Vector2f myPosition = tank.getPosition();
	if (getPosition().x > myPosition.x) {
		setRotation(270);
		direction = 'A';
		if (!ifLeftBoundary() && ifLeftReach() == 0) {
			move(-getObstacleSpeed(), 0);
		}
		else if (!ifLeftBoundary() && ifLeftReach() == 1) {
			move(-1, 0);
		}
		else if (!ifLeftBoundary() && ifLeftReach() == 2) {
			if (!ifLeftObstacle()) {
				move(-getObstacleSpeed(), 0);
			}
		}
	}
	else if (getPosition().x < myPosition.x) {
		setRotation(90);
		direction = 'D';
		if (!ifRightBoundary() && ifRightReach() == 0) {
			move(getObstacleSpeed(), 0);
		}
		else if (!ifRightBoundary() && ifRightReach() == 1) {
			move(1, 0);
		}
		else if (!ifRightBoundary() && ifRightReach() == 2) {
			if (!ifRightObstacle()) {
				move(getObstacleSpeed(), 0);
			}
		}
	}
	else if (getPosition().y < myPosition.y) {
		setRotation(180);
		direction = 'S';
		if (!ifDownBoundary() && ifDownReach() == 0) {
			move(0, getObstacleSpeed());
		}
		else if (!ifDownBoundary() && ifDownReach() == 1) {
			move(0, 1);
		}
		else if (!ifDownBoundary() && ifDownReach() == 2) {
			if (!ifDownObstacle()) {
				move(0, getObstacleSpeed());
			}
		}
	}
	else if (getPosition().y > myPosition.y) {
		setRotation(0);
		direction = 'W';
		if (!ifUpBoundary() && ifUpReach() == 0) { 
			move(0, -getObstacleSpeed());
		}
		else if (!ifUpBoundary() && ifUpReach() == 1) {   
			move(0, -1);
		}
		else if (!ifUpBoundary() && ifUpReach() == 2) {
			if (!ifUpObstacle()) {
				move(0, -getObstacleSpeed());
			}
		}
	}
}

Enemy::Enemy(int heal, int da, char di, int fi) {
	health = heal;
	damage = da;
	direction = di;
	bulletControll = fi;
}