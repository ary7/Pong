#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Paddle.h"


class Ball : public Paddle
{
	public:

		Ball();
		Ball(sf::Vector2f initialPosition);
		~Ball();

		void MoveBall(sf::Time &deltaTime);
		void CollisionWithWall(sf::Time &deltaTime);


	private:

		sf::Vector2f size;
		sf::Vector2f initialPosition;
		sf::Vector2f velocity;

};
