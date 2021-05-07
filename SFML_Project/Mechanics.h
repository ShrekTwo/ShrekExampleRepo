#ifndef _MECHANICS_H_
#define _MECHANIOCS_H_

#include "Event_Handler.h"
#include "SFML/System/Clock.hpp"

#include <string>
#include <sstream>

class Mechanics
{
private:
	static sf::Clock clock;
	static int speed;

	static std::string fpsString;

	static int counetr;
	static int fps;
	static int frameRate;
public:
	static void sprite_move_up();
	static void sprite_move_down();
	static void sprite_move_left();
	static void sprite_move_right();
	static void sprite_movement();
	//static void movement_to_time(int x, int y);
	static std::string fps_to_string();
	static int get_frame_rate();
};
#endif /*_MECHANICS_H_*/