#include "Texture_Loader.h"

sf::Texture Texture_Loader::texture;
sf::Sprite Texture_Loader::sprite;


sf::Sprite Texture_Loader::sprite_load(std::string filename) {
	Texture_Loader::texture_load(filename);
	Texture_Loader::sprite.setTexture(Texture_Loader::texture);

	//Texture_Loader::sprite.setPosition(sf::Vector2f(500.f, 250.f));
	Texture_Loader::sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	//Texture_Loader::sprite.setOrigin(sf::Vector2f(Texture_Loader::sprite.get, ));

	return Texture_Loader::sprite;
}

void Texture_Loader::texture_load(std::string filename) {

	if (!Texture_Loader::texture.loadFromFile(filename)) {
		std::cerr<<"Texture loader issue: failed to load a texture" << std::endl;
	}
	//Texture_Loader::texture.loadFromFile(filename);
	Texture_Loader::texture.setSmooth(true);
	//return Texture_Loader::texture;
}