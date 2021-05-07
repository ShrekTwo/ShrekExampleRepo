#include "Mechanics.h"
#include "Texture_Loader.h"

sf::Clock Mechanics::clock;
int Mechanics::speed = 300;

std::string Mechanics::fpsString;

int Mechanics::counetr;
int Mechanics::fps;
int Mechanics::frameRate;

void Mechanics::sprite_movement() {
	Mechanics::sprite_move_up();
	Mechanics::sprite_move_down();
	Mechanics::sprite_move_left();
	Mechanics::sprite_move_right();
}

void Mechanics::sprite_move_up() {
	if (Event_Handler::W_key_pressed == true && Event_Handler::W_key_released == false)
	{
		Texture_Loader::sprite.move(0.f, -20.f);
	}
}

void Mechanics::sprite_move_left() {
	if (Event_Handler::A_key_pressed == true && Event_Handler::A_key_released == false)
	{
		Texture_Loader::sprite.move(-20.f, 0.f);
	}
}

void Mechanics::sprite_move_down() {
	if (Event_Handler::S_key_pressed == true && Event_Handler::S_key_released == false)
	{
		Texture_Loader::sprite.move(0.f, 20.f);
	}
}

void Mechanics::sprite_move_right() {
	if (Event_Handler::D_key_pressed == true && Event_Handler::D_key_released == false)
	{
		Texture_Loader::sprite.move(20.f, 0.f);
	}
}

std::string Mechanics::fps_to_string() {

	return Mechanics::fpsString;
}

int Mechanics::get_frame_rate() {

	return 0;
}

/*
void Mechanics::movement_to_time(int x, int y) {
	sf::Time elapsedTime = Mechanics::clock.restart();
	float tempSpeed = elapsedTime.asSeconds() * speed;
	Texture_Loader::sprite.move(tempSpeed*x, tempSpeed*y);
}
*/