
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include<vector>
#include "Tank.h"
#include "TileMap.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Define.h"
#include "Map.h"
#include "Universe.h"
#include <ctime>
#include "windows.h"


struct point
{
	int x;
	int y;
};



std::vector<Bullet> Universe::BulletBuf = std::vector<Bullet>();
std::vector<Enemy> Universe::EnemyBuf = std::vector<Enemy>();
std::vector<Tank> Universe::MyTank = std::vector<Tank>();
std::vector<Bullet> Universe::EnmeyBulletBuf = std::vector<Bullet>();
sf::Sprite fire;


Tank tank(TankHealth, TankDamage, 'D', 0);
int score = 0;
bool gameOver = false;

int main();

void CheckEnemyAttacked(sf::Text* text2) {

	auto& Bullet_Buf = Universe::BulletBuf;
	auto& Enemy_Buf = Universe::EnemyBuf;
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

					
					//огонь
					fire.setPosition(Enemy_Buf.at(i).getPosition().x-25, Enemy_Buf.at(i).getPosition().y - 25);
					

					score++;
					std::cout << "Your Score:  " << score << std::endl << std::endl;
					(*text2).setString("Your Score: " + std::to_string(score));
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

void CheckMeAttacked(sf::Text * text, sf::Window * window) {

	auto& EnemyBullet = Universe::EnmeyBulletBuf;
	for (int i = 0; i < EnemyBullet.size(); i++) {
		sf::FloatRect TankPosition = tank.getGlobalBounds();
		sf::FloatRect BulletPosition = EnemyBullet.at(i).getGlobalBounds();
		if (TankPosition.intersects(BulletPosition) == 1) {

			int newHealth = tank.getHealth() - EnemyBullet.at(i).getBulletDamage();
			std::cout << "Your Health: " << newHealth << std::endl << std::endl;
			(*text).setString("Your Health: " + std::to_string(newHealth));
			tank.setHealth(newHealth);
			auto itr = EnemyBullet.begin();
			EnemyBullet.erase(itr + i);
			i--;


			if (tank.getHealth() <= 0) {
				std::cout << "---------------------------------------" << std::endl;
				std::cout << "Game Over!" << std::endl;


				sf::SoundBuffer buffer;
				//buffer.loadFromFile("C:/Users/mikha/source/repos/firs_game/firs_game/image-folder/shoot.ogg");
				sf::Sound sound;
				buffer.loadFromFile("C:/Users/mikha/source/repos/firs_game/firs_game/image-folder/tank-unichtozhen.ogg");


				sound.setBuffer(buffer);
				sound.setVolume(50);
				sound.play();



				sf::RenderWindow window2(sf::VideoMode(300, 100), "Game Over"); // создание второго окна

				

				sf::Font font;
				font.loadFromFile("C:/Users/mikha/source/repos/firs_game/firs_game/image-folder/calibri.ttf");

				sf::Text text("Game Over!!!   You score: " + std::to_string(score), font, 20);

				//text.setColor(sf::Color(0,0,0,255));
				text.setOutlineColor(sf::Color::Red);
				text.setFillColor(sf::Color::Red);


				window2.display(); // показываем второе
				window2.draw(text);
				window2.display();

				//Sleep(3000);
				//window2.close();

				//(*window).setActive(true);
				//(*window).requestFocus();


				
				//window2.clear();
				

				//system("Pause");
				
				while (window2.isOpen())
				{
					sf::Event event;
					while (window2.pollEvent(event)) {
						if (event.type == sf::Event::Closed)
						{
							window2.close();
							(*window).close();
							break;
						}
						if (event.key.code == sf::Keyboard::Escape)
						{
							window2.close();
							(*window).close();
							break;
						}

						/*if (event.key.code == sf::Keyboard::LControl)
						{
							break;
						}*/
					}
				}
				


				newHealth = TankHealth;
				tank.setHealth(newHealth);
				Universe::EnemyBuf.clear();
				/*main();
				gameOver = true;*/



			}
		}
	}

}

void CreateEnemy() {

	auto& Enemy_Buf = Universe::EnemyBuf;
	if (Enemy_Buf.size() <= 4) {
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

	srand(time(NULL));
	sf::SoundBuffer buffer;
	buffer.loadFromFile("C:/Users/mikha/source/repos/firs_game/firs_game/image-folder/shoot.ogg");
	sf::Sound sound;
	sound.setBuffer(buffer);


	sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "Tanks Battle");
	window.setFramerateLimit(60);
	

	sf::Font font;
	font.loadFromFile("C:/Users/mikha/source/repos/firs_game/firs_game/image-folder/calibri.ttf");
	//sf::Text text("Esc - Exit / Arrow Keys - Move Tile", font, 20);
	sf::Text text(" Your Health : full", font, 25);


	sf::Vector2f shift1(400, 15);
	text.move(shift1);

	sf::Text text2(" - explosion    Your Score : 0", font, 25);
	sf::Vector2f shift2(50,15);
	text2.move(shift2);


	text.setOutlineColor(sf::Color::White);  
	text.setFillColor(sf::Color::White);

	sf::Texture texture_tank;
	texture_tank.loadFromFile("C:/Users/mikha/source/repos/firs_game/firs_game/image-folder/MyTank.jpg");



	//Взрыв

	sf::Texture texture_fire;
	texture_fire.loadFromFile("C:/Users/mikha/source/repos/firs_game/firs_game/image-folder/fire.png");
	fire.setTexture(texture_fire);






	sf::Texture texture_enemy;
	texture_enemy.loadFromFile("C:/Users/mikha/source/repos/firs_game/firs_game/image-folder/Enemy.jpg");


	TileMap map;
	map.load("C:/Users/mikha/source/repos/firs_game/firs_game/image-folder/tileset.png", sf::Vector2u(50, 50), Map::tilesArray, 16, 16);
	sf::Texture enemyBullet;
	enemyBullet.loadFromFile("C:/Users/mikha/source/repos/firs_game/firs_game/image-folder/Bullet.png");
	sf::Texture myBullet;
	myBullet.loadFromFile("C:/Users/mikha/source/repos/firs_game/firs_game/image-folder/bullet1.png");




	tank.setOrigin(25, 25);
	tank.setPosition(125, 175);
	tank.setTexture(texture_tank);
	tank.setObstacleSpeed(TankSpeed);

	Universe::MyTank.push_back(tank);


	/*---------------- game loop ---------------*/
	while (window.isOpen() && !gameOver) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.key.code == sf::Keyboard::Escape) window.close();

			if (event.key.code == sf::Keyboard::LControl) system("pause");
		}
		window.clear();
		/*---Update game---*/

		window.draw(map);

		window.draw(tank);
		window.draw(fire);
		tank.tankAction();
		CreateEnemy();
		CheckEnemyAttacked(&text2);
		CheckMeAttacked(&text, &window);


		/*if (gameOver)EnemyBuf
		{
			window.close();
			Universe::EnemyBuf.clear();
		}*/

		for (int i = 0; i < Universe::BulletBuf.size(); i++) {
			auto& MyBulletBuf = Universe::BulletBuf;
			MyBulletBuf.at(i).setTexture(myBullet);
			window.draw(MyBulletBuf.at(i));
			MyBulletBuf.at(i).bulletFly();
		}

		for (int i = 0; i < Universe::EnemyBuf.size(); i++) {
			auto& EnemyBuf = Universe::EnemyBuf;
			EnemyBuf.at(i).setTexture(texture_enemy);
			window.draw(EnemyBuf.at(i));
			EnemyBuf.at(i).enemyAction();
		}

		for (int i = 0; i < Universe::EnmeyBulletBuf.size(); i++) {
			auto& EnemyBullet_Buf = Universe::EnmeyBulletBuf;
			EnemyBullet_Buf.at(i).setTexture(enemyBullet);
			window.draw(EnemyBullet_Buf.at(i));
			EnemyBullet_Buf.at(i).bulletFly();

		}


		///////

		window.draw(text);
		window.draw(text2);
		window.display();

	}


	return 0;
}



