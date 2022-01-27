#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace sf;

struct point
{
	int x;
	int y;
};


int main()
{
	srand(time(0));

	RenderWindow app(VideoMode(1500, 1000), "Doodle Game!"); 
	app.setFramerateLimit(60);   //Ќастройка частоты обновлени€ кадров(фиксированна€ частота)
								 //¬нутри использует sf::sleep. ѕросит перерисовать картинку... 
								 // через определенный промежуток времени
	
	Texture t1, t2, t3;
	t1.loadFromFile("image_for_game/fon.png");
	t2.loadFromFile("image_for_game/stupen.png");
	t3.loadFromFile("image_for_game/doodle.png");

	Sprite sBackground(t1), sPlat(t2), sPers(t3);
	sPers.setTextureRect(IntRect(100, 100, 250, 250));

	point plat[20];

	int x = 0, y = 0, h = 0;
	float dx = 0, dy = 0;

	bool isFind = false;

	while (app.isOpen())
	{
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				app.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) x += 5;
		if (Keyboard::isKeyPressed(Keyboard::Left)) x -= 5;
		if (Keyboard::isKeyPressed(Keyboard::Up)) y -= 5;
		if (Keyboard::isKeyPressed(Keyboard::Down)) y += 5;


		
		sPers.setPosition(x, y);
		sPlat.setPosition(500, 500);

		if (sPers.getPosition() == sPlat.getPosition())
		{
			isFind = true;
		}
		


		app.draw(sBackground);
		app.draw(sPers);

		if (!isFind)
		{
			app.draw(sPlat);
		}
		

		app.display();

	}

	return 0;
}


