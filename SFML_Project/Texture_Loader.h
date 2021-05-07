#ifndef _TEXTURE_LOADER_H_
#define _TEXTURE_LOADER_H_

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

#include <iostream>
#include <string>


class Texture_Loader
{
public:
	static sf::Sprite sprite;
	static sf::Texture texture;
	static void texture_load(std::string filename);
	static sf::Sprite sprite_load(std::string filename);
};


#endif /*_TEXTURE_LOADER_H_*/