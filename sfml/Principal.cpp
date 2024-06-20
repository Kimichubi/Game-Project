#include "Principal.h"

Jungle::Principal::Principal() :
	window(sf::VideoMode(800.0f, 600.0f), "Jungle++"), jogador(sf::Vector2f(100.0f, 200.0f), sf::Vector2f(50.0f, 50.0f))
{
	executar();
}

Jungle::Principal::~Principal() {
}

void Jungle::Principal::executar() {
	while (window.isOpen()) {
		sf::Event evento;
		if (window.pollEvent(evento)) {
			if (evento.type == sf::Event::Closed) {
				window.close();
			}
			else if (evento.type == sf::Event::KeyPressed) {
				if (evento.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
		}
		window.clear();
		jogador.move();
		window.draw(jogador.getCorpo());
		window.display();
	}
}