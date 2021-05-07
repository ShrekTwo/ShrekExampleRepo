#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

#include "SFML/Window/Event.hpp"
#include <iostream>

class Event_Handler
{
public:

	static bool W_key_pressed;
	static bool A_key_pressed;
	static bool S_key_pressed;
	static bool D_key_pressed;

	static bool W_key_released;
	static bool A_key_released;
	static bool S_key_released;
	static bool D_key_released;


	static sf::Event event;
	static void event_handling();
	static void close_window_event();
	static void keyboard_events_pressed();
	static void keyboard_events_released();
	static void left_click();
	//static void window_pause();
	//static void window_resume();
};

#endif /*_EVENT_HANDLER_H_*/