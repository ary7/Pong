#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"


class Paddle : public sf::RectangleShape
{
	public:

		Paddle();
		Paddle(sf::Vector2f initialPosition);
		~Paddle();

		float GetX();
		float GetY();

		void MovePaddle(sf::Event &event, sf::Time &deltaTime);

	private:

		sf::Vector2f size;
		sf::Vector2f initialPosition;
		
};