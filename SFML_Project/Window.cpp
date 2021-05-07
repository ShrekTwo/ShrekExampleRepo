
#include "Window.h"
#include "Texture_Loader.h"
#include "Event_Handler.h"
#include "Mechanics.h"


sf::RenderWindow Window::window;
sf::Color Window::color(6, 98, 101);


void Window::close_window() {
	Window::window.close();
}

void Window::run_window() {

	while (Window::window.isOpen()) {


		Event_Handler::event_handling();

		Window::window.clear(Window::color);

		Window::window.draw(Texture_Loader::sprite_load("png_src/molot.png"));
		Mechanics::sprite_movement();

		Window::window.display();
	}
}

void Window::create_window(uint width, uint lenght, std::string title){

	Window::window.create(sf::VideoMode(width, lenght), title);
	Window::window.setKeyRepeatEnabled(false);
	Window::window.setFramerateLimit(60);
	//Window::window.setVerticalSyncEnabled(true);
}