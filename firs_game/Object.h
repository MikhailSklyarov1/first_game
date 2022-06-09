#pragma once
#include <SFML/Graphics.hpp>

class Object : public sf::Sprite {

private:
	int speed;

public:
	void setObstacleSpeed(int sp) { speed = sp; }
	int getObstacleSpeed() { return speed; }
	
public:
	bool ifLeftBoundary();
	bool ifRightBoundary();
	bool ifUpBoundary();
	bool ifDownBoundary();
	
public:
	int ifLeftReach();
	int ifRightReach();
	int ifUpReach();
	int ifDownReach();

public:
	bool ifLeftObstacle();
	bool ifRightObstacle();
	bool ifUpObstacle();
	bool ifDownObstacle();

};




