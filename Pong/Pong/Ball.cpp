#include "Ball.h"

Ball::Ball()
{

}

Ball::Ball(sf::Vector2f initialPosition)
{
	setSize(sf::Vector2f(BALL_DIAMETER, BALL_DIAMETER));
	setPosition(initialPosition);
	velocity = sf::Vector2f(BALL_SPEED, BALL_SPEED);
}

Ball::~Ball()
{
}

void Ball::MoveBall(sf::Time & deltaTime)
{
	move(velocity.x * deltaTime.asMilliseconds(), velocity.y * deltaTime.asMilliseconds());
}

void Ball::CollisionWithWall(sf::Time &deltaTime)
{
	if ((GetX() <= 0) || (GetX() + (BALL_DIAMETER) >= SCREEN_WIDTH))
	{
		cout << GetX() << endl;
		if (GetX() < 0)
		{
			setPosition(sf::Vector2f(0, GetY()));
			velocity.x *= -1;
		}
		else
		{
			setPosition(sf::Vector2f(780, GetY()));
			velocity.x *= -1;
		}
	}

	if ((GetY() <= 0) || (GetY() + (BALL_RADIUS) >= SCREEN_HEIGHT))
	{
		cout << GetY() << endl;
		if (GetY() < 300)
		{
			setPosition(sf::Vector2f(GetX(), 0));
			velocity.y *= -1;
		}
		else
		{
			setPosition(sf::Vector2f(GetX(), 580));
			velocity.y *= -1;
		}
		
	}

}


