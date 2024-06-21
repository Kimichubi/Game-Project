#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#pragma once

class Game
{
public:
	Game();
	~Game();
	void config();
	void execute();

private:

	sf::RenderWindow window;
	sf::Event ev;
	sf::Texture textureBackground;
	sf::Sprite spriteBackground;
	Player player;
};
