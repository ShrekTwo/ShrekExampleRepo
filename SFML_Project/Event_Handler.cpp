#include "Event_Handler.h"
#include "Window.h"

sf::Event Event_Handler::event;

bool Event_Handler::W_key_pressed = false;
bool Event_Handler::A_key_pressed = false;
bool Event_Handler::S_key_pressed = false;
bool Event_Handler::D_key_pressed = false;

bool Event_Handler::W_key_released = true;
bool Event_Handler::A_key_released = true;
bool Event_Handler::S_key_released = true;
bool Event_Handler::D_key_released = true;

void Event_Handler::event_handling() {
	while (Window::window.pollEvent(Event_Handler::event)) {

		switch (Event_Handler::event.type) {
			case sf::Event::Closed:
				Event_Handler::close_window_event();
				break;
			case sf::Event::KeyPressed:
				Event_Handler::keyboard_events_pressed();
				break;
			case sf::Event::KeyReleased:
				Event_Handler::keyboard_events_released();
				break;
			case sf::Event::Resized:
				std::cout << "Window log: window has been resized: " << Window::window.getSize().x << " by " << Window::window.getSize().y << std::endl;
				break;
			case sf::Event::LostFocus:
				std::cout << "Window log: window has lost focus" << std::endl;
				break;
			case sf::Event::GainedFocus:
				std::cout << "Window log: window has gained focus" << std::endl;
				break;
			case sf::Event::MouseButtonPressed:
				if (Event_Handler::event.mouseButton.button == sf::Mouse::Left)
					Event_Handler::left_click();
				break;

			default:
				break;
		}
	}
}

void Event_Handler::close_window_event() {
	if (Event_Handler::event.type == sf::Event::Closed)
		Window::close_window();
}

void Event_Handler::keyboard_events_pressed() {
	//control keys
	if (Event_Handler::event.key.code == sf::Keyboard::W) {
		Event_Handler::W_key_pressed = true;
		Event_Handler::W_key_released = false;
	}
	if(Event_Handler::event.key.code == sf::Keyboard::A){
		Event_Handler::A_key_pressed = true;
		Event_Handler::A_key_released = false;
	}
	if(Event_Handler::event.key.code == sf::Keyboard::S){
		Event_Handler::S_key_pressed = true;
		Event_Handler::S_key_released = false;
	}
	if(Event_Handler::event.key.code == sf::Keyboard::D){
		Event_Handler::D_key_pressed = true;
		Event_Handler::D_key_released = false;
	}
	if (Event_Handler::event.key.code == sf::Keyboard::Escape)
		Window::close_window();
}

void Event_Handler::keyboard_events_released(){
	//control keys
	if (Event_Handler::event.key.code == sf::Keyboard::W) {
		Event_Handler::W_key_pressed = false;
		Event_Handler::W_key_released = true;
	}
	if (Event_Handler::event.key.code == sf::Keyboard::A) {
		Event_Handler::A_key_pressed = false;
		Event_Handler::A_key_released = true;
	}
	if (Event_Handler::event.key.code == sf::Keyboard::S) {
		Event_Handler::S_key_pressed = false;
		Event_Handler::S_key_released = true;
	}
	if (Event_Handler::event.key.code == sf::Keyboard::D) {
		Event_Handler::D_key_pressed = false;
		Event_Handler::D_key_released = true;
	}
}

void Event_Handler::left_click() {
	std::cout << "Mouse Position: " << Event_Handler::event.mouseMove.x << " " << Event_Handler::event.mouseMove.y << std::endl;
}