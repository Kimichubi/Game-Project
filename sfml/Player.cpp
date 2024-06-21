#include "Player.h"
#include <iostream>

Player::Player() : body(), currentFrame(0), animationTime(sf::seconds(0.05f)), elapsedTime(sf::Time::Zero), animationState(Idle)
{
	this->config();
}

Player::~Player()
{
}

void Player::config()
{
	this->body.setSize(sf::Vector2f(250.f, 250.f));
	this->body.setPosition(sf::Vector2f(100.f, 250.f));

	this->loadTextures();
	this->body.setTexture(&this->idleTextures[0]);
}

void Player::loadTextures()
{
	sf::Texture texture;

	for (int i = 1; i <= 10; ++i)
	{
		texture.loadFromFile("../content/adventure_girl/png/Idle (" + std::to_string(i) + ").png");
		texture.setSmooth(true);
		this->idleTextures.push_back(texture);
	}

	for (int i = 1; i <= 10; ++i)
	{
		texture.loadFromFile("../content/adventure_girl/png/Run (" + std::to_string(i) + ").png");
		texture.setSmooth(true);
		this->runTextures.push_back(texture);
	}

	for (int i = 1; i <= 10; ++i)
	{
		texture.loadFromFile("../content/adventure_girl/png/Run (" + std::to_string(i) + ").png");
		texture.setSmooth(true);
		this->runTextures.push_back(texture);
	}

	for (int i = 1; i <= 10; ++i)
	{
		texture.loadFromFile("../content/adventure_girl/png/Melee (" + std::to_string(i) + ").png");
		texture.setSmooth(true);
		this->attackTextures.push_back(texture);
	}
	for (int i = 1; i <= 10; ++i)
	{
		texture.loadFromFile("../content/adventure_girl/png/Shoot (" + std::to_string(i) + ").png");
		texture.setSmooth(true);
		this->shootTextures.push_back(texture);
	}
}

void Player::move()
{
	auto horizontal = sf::Vector2f(0.1f, 0.1f);

	this->animationTime = sf::seconds(0.05f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->body.move(sf::Vector2f(-horizontal.y, 0.f));
		this->animationState = RunningLeft;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->body.move(sf::Vector2f(horizontal.x, 0.f));
		this->animationState = RunningRight;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		this->body.move(sf::Vector2f(0.f, 0.f));
		this->animationState = Attack;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		this->body.move(sf::Vector2f(0.f, 0.f));
		this->animationTime = sf::seconds(0.10f);
		this->animationState = Shoot;
	}
	else
	{
		this->animationState = Idle;
	}

	this->updateAnimation();
}

void Player::updateAnimation()
{
	this->elapsedTime += this->clock.restart();
	if (this->elapsedTime >= this->animationTime)
	{
		this->elapsedTime -= this->animationTime;
		this->currentFrame = (this->currentFrame + 1) % this->idleTextures.size();

		switch (this->animationState)
		{
		case Idle:
			this->body.setTexture(&this->idleTextures[this->currentFrame]);
			break;
		case RunningLeft:
			this->body.setTexture(&this->runTextures[this->currentFrame]);
			break;
		case RunningRight:
			this->body.setTexture(&this->runTextures[this->currentFrame]);
			break;
		case Attack:
			this->body.setTexture(&this->attackTextures[this->currentFrame]);
			break;
		case Shoot:
			this->body.setTexture(&this->shootTextures[this->currentFrame]);
			break;
		}
	}
}

const sf::RectangleShape Player::getBody() const
{
	return this->body;
}