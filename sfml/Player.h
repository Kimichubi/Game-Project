#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>

class Player
{
public:
	Player();
	~Player();

	void config();
	void move();
	const sf::RectangleShape getBody() const;

private:
	void loadTextures();
	void updateAnimation();

	sf::RectangleShape body;
	std::vector<sf::Texture> idleTextures;
	std::vector<sf::Texture> runTextures;
	std::vector<sf::Texture> attackTextures;
	std::vector<sf::Texture> shootTextures;
	size_t currentFrame;
	sf::Clock clock;
	sf::Time animationTime;
	sf::Time elapsedTime;
	enum AnimationState { Idle, RunningLeft, RunningRight, Attack, Shoot } animationState;
};

#endif
