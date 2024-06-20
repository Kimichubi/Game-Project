#include "Jogador.h"

Jungle::Jogador::Jogador::Jogador() : corpo() {
	inicializa();
}

Jungle::Jogador::Jogador::Jogador(const sf::RectangleShape corpo) : corpo(corpo) {
	inicializa();
}

Jungle::Jogador::Jogador::Jogador(const sf::Vector2f pos, const sf::Vector2f tam) : corpo(sf::RectangleShape(tam)) {
	corpo.setPosition(pos);
	corpo.setFillColor(sf::Color::Green);
	inicializa();
}

Jungle::Jogador::Jogador::~Jogador() {
}

void Jungle::Jogador::Jogador::inicializa() {
	vel = sf::Vector2f(0.1f, 0.1f);
}

void Jungle::Jogador::Jogador::move() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		corpo.move(-vel.x, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		corpo.move(vel.x, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		corpo.move(0.0f, -vel.y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		corpo.move(0.0f, vel.y);
	}
}

const sf::RectangleShape Jungle::Jogador::Jogador::getCorpo() {
	return corpo;
}