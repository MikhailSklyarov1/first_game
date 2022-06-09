#include "Tank.h"
#include "Bullet.h"
#include "Universe.h"
#include <vector>
#include <iostream>
#include "Map.h"
#include <math.h>
#include "Define.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



Tank::Tank(int heal, int da, char di, int fi) {

	damage = da;
	health = heal;
	direction = di;
	fireController = fi;

}


void Tank::tankMove() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) {
		setRotation(270);
		direction = 'A';	
		if (!ifLeftBoundary() && ifLeftReach()==0) {		
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) {
		setRotation(90);
		direction = 'D';
		if (!ifRightBoundary() && ifRightReach()==0) {
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) {
		setRotation(0);
		direction = 'W'; 
		if (!ifUpBoundary() && ifUpReach()==0) {  
			move(0, -getObstacleSpeed());
		}
		else if (!ifUpBoundary() && ifUpReach()==1) {   
			move(0, -1);
		}
		else if (!ifUpBoundary() && ifUpReach() == 2) {
			if (!ifUpObstacle()) {
				move(0, -getObstacleSpeed());
			}
		}

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) {
		setRotation(180);
		direction = 'S';
		if (!ifDownBoundary() && ifDownReach()==0) {
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
	
}

void Tank::tankFire() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (getFireController() % 5 == 0) {
			Bullet bullet = Bullet(getDamage(), getDirection());
			bullet.setOrigin(10, 10);
			bullet.setObstacleSpeed(BulletSpeed);
			bullet.setPosition(getPosition());
			bullet.setRotation(getRotation());
			Universe::BulletBuf.push_back(bullet);
		}	
		controllerAdd();
	}

}

void Tank::tankAction() {

	tankMove();
	tankFire();

}

