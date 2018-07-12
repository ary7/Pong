#include "Paddle.h"

Paddle::Paddle()
{
}

Paddle::Paddle(sf::Vector2f initialPosition)
{
	setSize(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));
	setPosition(initialPosition);
}

Paddle::~Paddle()
{
}

float Paddle::GetX()
{
	return getPosition().x;
}

float Paddle::GetY()
{
	return getPosition().y;
}

void Paddle::MovePaddle(sf::Event &event, sf::Time &deltaTime)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
	{
		if (GetY() <= 0)
		{
			setPosition(GetX(), 0);
		}
		else
		{
			move(0, -PADDLE_SPEED * deltaTime.asMilliseconds());
		}
	}
	else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
	{
		if (GetY() >= SCREEN_HEIGHT - PADDLE_HEIGHT)
		{
			setPosition(GetX(), SCREEN_HEIGHT - PADDLE_HEIGHT);
		}
		else
		{
			move(0, PADDLE_SPEED * deltaTime.asMilliseconds());
		}
	}
}

