#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector3.hpp>
#include <cstdlib> // Para rand() e srand()
#include <ctime>   // Para time()
#include <iostream>
#include <cstdlib> // Para system()
// Construtor
Game::Game() : window(), ev(), textureBackground(), spriteBackground(), player()
{
	this->config();
	this->execute();
}

// Destrutor
Game::~Game()
{
}

void Game::execute()
{
	while (this->window.isOpen())
	{
		this->player.move();
		while (this->window.pollEvent(this->ev))
		{
			this->player.move();
			switch (this->ev.type)
			{
			case sf::Event::Closed:
				this->window.close();
				break;
			case sf::Event::KeyPressed:
				if (this->ev.key.code == sf::Keyboard::Escape)
				{
					this->window.close();

					break;
				}

			default:
				break;
			}
		}

		//Window Methods
		//Clear
		this->window.clear(sf::Color::White);
		//Draw
		this->window.draw(this->spriteBackground);
		this->window.draw(this->player.getBody());
		//Display
		this->window.display();
	}
}

void Game::config()
{
	this->window.create(sf::VideoMode(1200, 562), "GameProject");
	this->textureBackground.loadFromFile("C:/Users/gabri/OneDrive/Desktop/sfml/content/pngtree-d-game-art-natural-landscape-for-games-mobile-applications-and-computers-picture-image_2076743/pngtree-d-game-art-natural-landscape-for-games-mobile-applications-and-computers-picture-image_2076743.jpg");
	this->spriteBackground.setTexture(this->textureBackground);
}