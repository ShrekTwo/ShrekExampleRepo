#include <iostream>
#include <string>
#include <vector>

#include "SFML/Graphics.hpp"

void jump(sf::Sprite& obj){
	obj.move(0.f, -200.f);
}

int main() {
	sf::Vector2f charScale(3.f,3.f);
	
	sf::Vector2f stayStill(0.f, 0.f);
	sf::Vector2f charMove;
	sf::Vector2f velocity(5.f, 0.f);
	sf::Vector2f gravity(0.f, 2.f);

	sf::Texture texture;
	sf::Color colorGrey(152, 163, 155);

	const float maxY = 50.f;

	bool moveLeft = false;
	bool moveRight = false;
	bool isOnGround = true;

	sf::Texture charTexture;
	sf::Sprite charSprite;
	if (!charTexture.loadFromFile("textures/char.png")) {
		std::cerr << "TEXTURE LOAD FAILURE:: failed to load charTexture" << std::endl;
		return -1;
	}

	charSprite.setTexture(charTexture);
	charSprite.setScale(charScale);
	charSprite.setOrigin(charSprite.getTexture()->getSize().x * 0.5, charSprite.getTexture()->getSize().y * 0.5);


	std::vector<sf::Texture> zxKeyText(2);
	zxKeyText.at(0).loadFromFile("textures/m1.png");
	zxKeyText.at(1).loadFromFile("textures/m2.png");

	std::vector<sf::Sprite> zxKeySprite(2);

	for (int i = 0; i < zxKeyText.size(); i++) {
		zxKeySprite.at(i).setTexture(zxKeyText.at(i));
		zxKeySprite.at(i).setOrigin(zxKeySprite.at(i).getTexture()->getSize().x * 0.5, zxKeySprite.at(i).getTexture()->getSize().y * 0.5);
	}
	

	/*std::vector<sf::Texture> textureVector;
	textureVector.resize(2);
	textureVector.at(0).loadFromFile("textures/texture1.jpg");
	textureVector.at(1).loadFromFile("textures/texture2.png");

	std::vector<sf::Sprite> spritesVector;
	spritesVector.resize(2);
	spritesVector.at(0).setTexture(textureVector.at(0));
	spritesVector.at(1).setTexture(textureVector.at(1));*/

	sf::Color color(6, 98, 101);

	if (!texture.loadFromFile("textures/bruh.jpg")) {
		std::cerr << "TEXTURE:: failed to load texture from file" << std::endl;
		return 0;
	}

	texture.setSmooth(true);

	sf::Sprite sprite (texture);
	sprite.setScale(0.2f, 0.2f);

	bool isMove = false;
	float dx = 0, dy = 0;

	int fpsi;
	

	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(1280, 720), "",sf::Style::Close);
	window.setFramerateLimit(144);
	window.setMouseCursorVisible(false);
	

	sf::Texture cursor;
	if (!cursor.loadFromFile("textures/cursor.png")) {
		std::cerr << ("TEXTURE::CURSOR:: failed to load a cursor image") << std::endl;;
		return 0;
	}
	cursor.setSmooth(true);
	sf::Sprite CursorSprite(cursor);

	CursorSprite.setOrigin(CursorSprite.getTexture()->getSize().x * 0.5, CursorSprite.getTexture()->getSize().y * 0.5);
	CursorSprite.setScale(0.7f, 0.7f);

	zxKeySprite.at(0).setPosition(window.getSize().x  - zxKeySprite.at(0).getTexture()->getSize().x *0.5 - 4 ,window.getSize().y * 0.5 - 32);
	zxKeySprite.at(1).setPosition(window.getSize().x  - zxKeySprite.at(0).getTexture()->getSize().x *0.5 - 4,window.getSize().y * 0.5 + 4);

	charSprite.setPosition(charSprite.getTexture()->getSize().x*1.5, window.getSize().y * 0.5);

	while (window.isOpen()) {
		sf::Event event;
		sf::Vector2i mPos = sf::Mouse::getPosition(window);

		float fps = 1.f / clock.getElapsedTime().asSeconds();
		clock.restart();

		fpsi = (int)fps;

		std::string str = std::to_string(fpsi);
		window.setTitle(str);

		while (window.pollEvent(event)) {

			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:
					if(event.key.code == sf::Mouse::Left)
						if (sprite.getGlobalBounds().contains(mPos.x, mPos.y)) {
							isMove = true;
							dx = mPos.x - sprite.getPosition().x;
							dy = mPos.y - sprite.getPosition().y;
						}
					break;


			case sf::Event::MouseButtonReleased:
				if (event.key.code == sf::Mouse::Left)
					isMove = false;
				break;

			case sf::Event::KeyPressed:

				//if(event.key.code == sf::Keyboard::Z)
				//	zxKeySprite.at(0).setColor(sf::Color::Green);

				switch (event.key.code) {
					case sf::Keyboard::Escape:
						window.close();
						break;

					case sf::Keyboard::Z:
						zxKeySprite.at(0).setColor(colorGrey);
						zxKeySprite.at(0).setScale(1.2f, 1.2f);
						break;

					case sf::Keyboard::X:
						zxKeySprite.at(1).setColor(colorGrey);
						zxKeySprite.at(1).setScale(1.2f, 1.2f);
						break;

					case sf::Keyboard::A:
						moveLeft = true;
						break;

					case sf::Keyboard::D:
						moveRight = true;
						break;

					case sf::Keyboard::Space:
						jump(charSprite);
						break;
				}
				break;

			case sf::Event::KeyReleased:
				//if(event.key.code == sf::Keyboard::Z)
				//	zxKeySprite.at(0).setColor(sf::Color::White);
				switch (event.key.code){
					case sf::Keyboard::Z:
						zxKeySprite.at(0).setColor(sf::Color::White);
						zxKeySprite.at(0).setScale(1.f, 1.f);
						break;

					case sf::Keyboard::X:
						zxKeySprite.at(1).setColor(sf::Color::White);
						zxKeySprite.at(1).setScale(1.f, 1.f);
						break;

					case sf::Keyboard::A:
						moveLeft = false;
						break;

					case sf::Keyboard::D:
						moveRight = false;
						break;
					}	
				break;
			}
		}
		if (isMove)
			sprite.setPosition(mPos.x - dx, mPos.y - dy);

		CursorSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

		charSprite.move(charMove);

		if (moveRight) {
			charSprite.setScale(charScale.x * -1, charScale.y);
			charMove.x = velocity.x;
		}
		 
		if (moveLeft) {
			charSprite.setScale(charScale.x, charScale.y);
			charMove.x = velocity.x*-1;
		}

		if(!moveRight && !moveLeft || moveRight && moveLeft)
			charMove = stayStill;

		if (charSprite.getPosition().y < window.getSize().y * 0.5)
			isOnGround = false;
		else
			isOnGround = true;
			
		if (!isOnGround)
		{
			charSprite.move(charMove);
			if(charMove.y < maxY)
				charMove += gravity;
		}
		else
			charMove.y = 0.f;

		window.clear(color);
		
		window.draw(sprite);

		//for(auto sprite:spritesVector)
		//	window.draw(sprite);

		for (auto zxsprite : zxKeySprite)
			window.draw(zxsprite);

		window.draw(charSprite);

		window.draw(CursorSprite);

		window.display();
	}
}