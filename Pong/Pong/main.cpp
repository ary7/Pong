#include <SFML/Graphics.hpp>

#include "Paddle.h"
#include "Ball.h"
#include "constants.h"

sf::RenderWindow window;

bool running = true;

void InitializeSFML(); //Initial window setup
void Draw(); //Handle all drawing calls
void Update(sf::Event &event, sf::Time deltaTime); //Handle main game loop function calls for updating
void HandleInput(sf::Event &event); //Checks and handles input events

Paddle player(PLAYER_INITIAL_POS), computer(COMP_INITIAL_POS);
Ball ball(BALL_INITIAL_POS);

int main()
{
	sf::Clock clock;
	sf::Time deltaTime = clock.getElapsedTime();
	

	InitializeSFML();

	while (running)
	{
		sf::Event event;
		deltaTime = clock.restart();

		HandleInput(event);

		if (clock.getElapsedTime() >= deltaTime)
		{
			deltaTime += sf::milliseconds(1000 / FRAME_RATE);

			Update(event, deltaTime);
			Draw();
			
		}
		

	}

	return 0;
}

void InitializeSFML()
{
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(FRAME_RATE);
}

void Draw()
{
	window.clear();
	window.draw(player);
	window.draw(computer);
	window.draw(ball);
	window.display();
}

void Update(sf::Event &event, sf::Time deltaTime)
{
	player.MovePaddle(event, deltaTime);
	computer.MovePaddle(event, deltaTime);


	ball.MoveBall(deltaTime);
	ball.CollisionWithWall(deltaTime);
}

void HandleInput(sf::Event &event)
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
		{
			window.close();
			running = false;
		}

	}
}

