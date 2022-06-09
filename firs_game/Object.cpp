#include "Object.h"
#include "Define.h"
#include "Map.h"


bool Object::ifLeftBoundary() {	
	sf::Vector2f ObjectCenter = getPosition();
	if (ObjectCenter.x > getTextureRect().width/2) {
		return 0;
	}
	else return 1;
}

bool Object::ifRightBoundary() {
	sf::Vector2f ObjectCenter = getPosition();
	if (ObjectCenter.x < WindowWidth - getTextureRect().width/2) {
		return 0;
	}
	else return 1;
}

bool Object::ifUpBoundary() {
	sf::Vector2f ObjectCenter = getPosition();
	if (ObjectCenter.y > getTextureRect().height/2) {
		return 0;
	}
	else return 1;
}

bool Object::ifDownBoundary() {
	sf::Vector2f ObjectCenter = getPosition();
	if (ObjectCenter.y < WindowWidth - getTextureRect().height / 2) {
		return 0;
	}
	else return 1;
}



bool Object::ifLeftObstacle() {
	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;

	FrontCorner1.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y + getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	FrontCorner2.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y - getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;


	if (j1 == (double)FrontCorner1.y / WallSize   
		|| j2 == (double)FrontCorner2.y / WallSize
		|| j1 == j2) {
		tile1 = Map::tilesArray[i2 + j2*Width - 1];
		tile2 = tile1;
	}
	
	else {  
		tile1 = Map::tilesArray[i1 + j1*Width - 1];
		tile2 = Map::tilesArray[i2 + j2*Width - 1];
	}

	if (tile1 != Water && tile1 != Tree && tile2 != Water && tile2 != Tree) {
		return 0;
	}
	else return 1;
		
}

bool Object::ifRightObstacle() {

	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;

	FrontCorner1.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y - getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	FrontCorner2.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y + getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;

	if (j1 == (double)FrontCorner1.y / WallSize
		|| j2 == (double)FrontCorner2.y / WallSize
		|| j1 == j2) {
		tile1 = Map::tilesArray[i1 + j1*Width];
		tile2 = tile1;
	}
	else {   	
		tile1 = Map::tilesArray[i1 + j1*Width];
		tile2 = Map::tilesArray[i2 + j2*Width];
	}

	if (tile1 != Water && tile1 != Tree && tile2 != Water && tile2 != Tree) {
		return 0;
	}
	else return 1;
		
}

bool Object::ifUpObstacle() {  


	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;

	FrontCorner1.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y - getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	FrontCorner2.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y - getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;

	if (i1 == (double)FrontCorner1.x / WallSize
		|| i2 == (double)FrontCorner2.x / WallSize
		|| i1 == i2) {
		tile1 = Map::tilesArray[i1 + (j1 - 1)*Width];
		tile2 = tile1;
	}
	else {
		tile1 = Map::tilesArray[i1 + (j1 - 1)*Width];
		tile2 = Map::tilesArray[i2 + (j2 - 1)*Width];
	}

	if (tile1 != Water && tile1 != Tree && tile2 != Water && tile2 != Tree) {
		return 0;
	}
	else {
		return 1;
	}
	
		
}

bool Object::ifDownObstacle() {

	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;

	FrontCorner1.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y + getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	FrontCorner2.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y + getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;

	if (i1 == (double)FrontCorner1.x / WallSize
		|| i2 == (double)FrontCorner2.x / WallSize
		|| i1 == i2) {
		tile1 = Map::tilesArray[i2 + j2*Width];
		tile2 = tile1;
	}	
	else {  
		tile1 = Map::tilesArray[i1 + j1*Width];
		tile2 = Map::tilesArray[i2 + j2*Width];
	}
	if (tile1 != Water && tile1 != Tree && tile2 != Water && tile2 != Tree) {
		return 0;
	}
	else {
		return 1;
	}	
}



int Object::ifLeftReach() {

	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;

	
	FrontCorner1.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y + getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	
	FrontCorner2.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y - getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;

	if (FrontCorner1.x - getObstacleSpeed() > i1*WallSize) { 
		return 0;
	}
	else if (FrontCorner1.x > i1*WallSize) {  
		return 1;
	}
	else return 2;
}

int Object::ifRightReach() {

	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;

	FrontCorner1.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y - getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	FrontCorner2.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y + getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;


	if (FrontCorner1.x == i1*WallSize) {
		return 2;
	}
	else if (FrontCorner1.x + getObstacleSpeed() < (i1 + 1)*WallSize) {
		return 0;
	}
	else if (FrontCorner1.x < (i1 + 1)*WallSize) {
		return 1;
	}
	
	
}

int Object::ifUpReach() {  

	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;

	
	FrontCorner1.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y - getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	
	FrontCorner2.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y - getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;

	if (FrontCorner1.y - getObstacleSpeed() > j1*WallSize) {   
		return 0;
	}
	else if (FrontCorner1.y > j1*WallSize) { 
		return 1;
	}
	else return 2;
}

int Object::ifDownReach() {

	int tile1, tile2;
	int i1, j1, i2, j2;
	sf::Vector2f FrontCorner1, FrontCorner2;


	FrontCorner1.x = getPosition().x + getTextureRect().width / 2;
	FrontCorner1.y = getPosition().y + getTextureRect().height / 2;
	i1 = FrontCorner1.x / WallSize;
	j1 = FrontCorner1.y / WallSize;

	FrontCorner2.x = getPosition().x - getTextureRect().width / 2;
	FrontCorner2.y = getPosition().y + getTextureRect().height / 2;
	i2 = FrontCorner2.x / WallSize;
	j2 = FrontCorner2.y / WallSize;

	if (FrontCorner1.y == j1*WallSize) {
		return 2;
	}
	else if (FrontCorner1.y + getObstacleSpeed() < (j1 + 1)*WallSize) {
		return 0;
	}
	else if (FrontCorner1.y < (j1 + 1)*WallSize) {
		return 1;
	}

}