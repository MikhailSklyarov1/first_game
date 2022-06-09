#pragma once
#include <string.h>
#include <SFML/Graphics.hpp>


class TileMap : public sf::Drawable, public sf::Transformable {

private:
	sf::VertexArray m_vertices;
	sf::Texture texture_tileset;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
	bool load(const std::string& fileName, sf::Vector2u tileSize, int *tileArray, unsigned int width, unsigned int height);

};
