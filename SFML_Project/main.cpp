#include "Window.h"

unsigned int WIDTH = 1600;
unsigned int HEIGHT = 900;

int main() {

	Window::create_window(WIDTH, HEIGHT, "nigga");
	Window::run_window();

	return 0;
}