#ifndef _WINDOW_H_
#define _WINDOW_H_

#include "SFML/Graphics/RenderWindow.hpp"

#include <string>

typedef unsigned int uint;

class Window
{
public:
	static sf::RenderWindow window;
	static sf::Color color;
	static void create_window(uint width, uint leight, std::string title);
	static void run_window();
	static void close_window();
};

#endif /*_WINDOW_H_*/