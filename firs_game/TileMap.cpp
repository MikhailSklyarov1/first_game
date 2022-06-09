#include "TileMap.h"
#include <SFML/Graphics.hpp>


void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	states.transform *= getTransform();
	states.texture = &texture_tileset;
	target.draw(m_vertices, states);

}


bool TileMap::load(const std::string& fileName, sf::Vector2u tileSize, int *tileArray, unsigned int width, unsigned int height) {

	if (!texture_tileset.loadFromFile("C:/Users/mikha/source/repos/firs_game/firs_game/image-folder/tileset.png")) {
		return false;
	}
	
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width*height * 4);

	for (unsigned int i = 0; i < width; i++) {    
		for (unsigned int j = 0; j < height; j++) {

			int tileNumber = tileArray[i + j*width];  


			int tu = tileNumber % (texture_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (texture_tileset.getSize().x / tileSize.x);

			sf::Vertex* quad = &m_vertices[(i + j*width) * 4];


			quad[0].position = sf::Vector2f(i*tileSize.x, j*tileSize.y);
			quad[1].position = sf::Vector2f((i + 1)*tileSize.x, j*tileSize.y);
			quad[2].position = sf::Vector2f((i + 1)*tileSize.x, (j + 1)*tileSize.y);
			quad[3].position = sf::Vector2f(i*tileSize.x, (j + 1)*tileSize.y);


			quad[0].texCoords = sf::Vector2f(tu*tileSize.x, tv*tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1)*tileSize.x, tv*tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1)*tileSize.x, (tv + 1)*tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu*tileSize.x, (tv + 1)*tileSize.y);
		}
	}

	return true;
}