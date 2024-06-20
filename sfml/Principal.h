#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Jogador.h"
namespace Jungle {
	class Principal
	{
	private:
		sf::RenderWindow window;
		Jogador::Jogador jogador;

	public:
		Principal();
		~Principal();
		void executar();
	};
}
