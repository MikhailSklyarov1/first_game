/*#include <SFML/Graphics.hpp>
#include <iostream>
#include<vector>
#include "Tank.h"
#include "TileMap.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Define.h"
#include "Map.h"
#include "Universe.h"


std::vector<Bullet> Universe::BulletBuf = std::vector<Bullet>();
std::vector<Enemy> Universe::EnemyBuf = std::vector<Enemy>();
std::vector<Tank> Universe::MyTank = std::vector<Tank>();
std::vector<Bullet> Universe::EnmeyBulletBuf = std::vector<Bullet>();

Tank tank(TankHealth, TankDamage, 'D', 0);
int score = 0;

void CheckEnemyAttacked() {

	auto &Bullet_Buf = Universe::BulletBuf;
	auto &Enemy_Buf = Universe::EnemyBuf;
	for (int i = 0; i < Enemy_Buf.size(); i++) {
		for (int j = 0; j < Bullet_Buf.size(); j++) {
			sf::FloatRect EnemyRect = Enemy_Buf.at(i).getGlobalBounds();
			sf::FloatRect BulletRect = Bullet_Buf.at(j).getGlobalBounds();
			if (BulletRect.intersects(EnemyRect) == 1) {

				
				int newHealth = Enemy_Buf.at(i).getHealth() - Bullet_Buf.at(j).getBulletDamage();
				Enemy_Buf.at(i).setHealth(newHealth);
				auto itr = Bullet_Buf.begin();
				Bullet_Buf.erase(itr + j);
				j--;

				
				if (Enemy_Buf.at(i).getHealth() <= 0) {  
					score++;
					std::cout << "Your Score:  " << score << std::endl << std::endl;
					auto itr = Enemy_Buf.begin();
					Enemy_Buf.erase(itr + i);	
					i--;
					break;
				}
			}
			else {
				
			}
		}
	}	
}

void CheckMeAttacked() {

	auto &EnemyBullet = Universe::EnmeyBulletBuf;
	for (int i = 0; i < EnemyBullet.size(); i++) {
		sf::FloatRect TankPosition = tank.getGlobalBounds();
		sf::FloatRect BulletPosition = EnemyBullet.at(i).getGlobalBounds();
		if (TankPosition.intersects(BulletPosition) == 1) {
			
			int newHealth = tank.getHealth() - EnemyBullet.at(i).getBulletDamage();
			std::cout << "Your Health: " << newHealth << std::endl << std::endl;
			tank.setHealth(newHealth);
			auto itr = EnemyBullet.begin();
			EnemyBullet.erase(itr + i);
			i--;

			
			if (tank.getHealth() <= 0) {
				std::cout << "---------------------------------------" << std::endl;
				std::cout << "Game Over!" << std::endl;
				system("Pause");
			}
		}
	}

}

void CreateEnemy() {

	auto &Enemy_Buf = Universe::EnemyBuf;
	if (Enemy_Buf.size() <= 5) {
		Enemy enemy(EnemyHealth, EnemyDamage, 'W', 0);
		enemy.setObstacleSpeed(1);
		enemy.setOrigin(25, 25);
		int random = rand() % 4;
		if (random == 0) {
			enemy.setPosition(175, 225);
		}
		else if (random == 1) {
			enemy.setPosition(175, 675);
		}
		else if (random == 2) {
			enemy.setPosition(675, 125);
		}
		else {
			enemy.setPosition(675, 675);
		}
		Enemy_Buf.push_back(enemy);
	}
	
}


int main() {

	sf::RenderWindow window(sf::VideoMode(WindowWidth,WindowHeight ), "TankWar");
	window.setFramerateLimit(60);

	sf::Texture texture_tank;
	texture_tank.loadFromFile("E:\\VS Files\\SFML_Programming\\MyTank.jpg");
	tank.setOrigin(25, 25); 
	tank.setPosition(125, 125);
	tank.setTexture(texture_tank);
	tank.setObstacleSpeed(TankSpeed);

	Universe::MyTank.push_back(tank);


	sf::Texture texture_enemy;
	texture_enemy.loadFromFile("E:\\VS Files\\SFML_Programming\\Enemy.jpg");


	TileMap map;
	map.load("E:\\VS Files\\SFML_Programming\\tileset.png", sf::Vector2u(50, 50), Map::tilesArray, 16, 16);
	  

	sf::Texture enemyBullet;
	enemyBullet.loadFromFile("D:\\VS Files\\SFML_Programming\\Bullet.png");
	sf::Texture myBullet;
	myBullet.loadFromFile("E:\\VS Files\\SFML_Programming\\bullet1.png");

	

	   
	while (window.isOpen()) {		
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();	
		}
		window.clear();
		

		window.draw(map);

	    window.draw(tank);
		tank.tankAction();
		CreateEnemy();
		CheckEnemyAttacked();
		CheckMeAttacked();

		for (int i = 0; i < Universe::BulletBuf.size(); i++) {
			auto &MyBulletBuf = Universe::BulletBuf;
			MyBulletBuf.at(i).setTexture(myBullet);
			window.draw(MyBulletBuf.at(i));
			MyBulletBuf.at(i).bulletFly();
		}

		for (int i = 0; i < Universe::EnemyBuf.size(); i++) {
			auto &EnemyBuf = Universe::EnemyBuf;
			EnemyBuf.at(i).setTexture(texture_enemy);
			window.draw(EnemyBuf.at(i));
			EnemyBuf.at(i).enemyAction();			
		}

		for (int i = 0; i < Universe::EnmeyBulletBuf.size(); i++) {
			auto &EnemyBullet_Buf = Universe::EnmeyBulletBuf;
			EnemyBullet_Buf.at(i).setTexture(enemyBullet);
			window.draw(EnemyBullet_Buf.at(i));
			EnemyBullet_Buf.at(i).bulletFly();
			
		}

		window.display();
	}

	return 0;
}  */



