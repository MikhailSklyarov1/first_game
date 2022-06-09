#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Universe.h"
#include <iostream>



Bullet::Bullet(int da, char di) {
	damage = da;
	direction = di;
}


void Bullet::bulletFly() {

	if (direction == 'W') {
		setRotation(0);
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
			else {
				bulletVanish();
			}
		}	
	}
	else if (direction == 'A') {
		setRotation(270);
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
			else {
				bulletVanish();
			}
		}
	}
	else if (direction == 'S') {
		setRotation(180);
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
			else {
				bulletVanish();

			}
		}
	}
	else if (direction == 'D') {
		setRotation(90);
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
			else {
				bulletVanish();
			}
		}
	}

}


void Bullet::bulletVanish() {

	for (int i = 0; i < Universe::BulletBuf.size(); i++) {
		if (this == &Universe::BulletBuf.at(i)) {
			auto &bullet_buf = Universe::BulletBuf;
			auto itr = bullet_buf.begin();
			bullet_buf.erase(itr + i);
		}
	}

	//this->getPosition

	for (int i = 0; i < Universe::EnmeyBulletBuf.size(); i++) {
		if (this == &Universe::EnmeyBulletBuf.at(i)) {
			auto &bullet_buf = Universe::EnmeyBulletBuf;
			auto itr = bullet_buf.begin();
			bullet_buf.erase(itr + i);
		}
	}

	//window.draw(herosprite);//
}


/*void Bullet::bulletVanish() {

	float frame = 0;
	float frameCount = 64;
	float animSpeed = 0.005;
	while (frame < frameCount) {
		spriteAnimation->setTextureRect(sf::IntRect(int(frame) * w, 0, w, w));
		frame += animSpeed;
		window->draw(rect); // clear the area of displaying animation
		window->draw(*spriteAnimation);
		window->display();

	}
}*/









