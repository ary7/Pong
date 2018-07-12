#pragma once
#define _USE_MATH_DEFINES

//screen constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int FRAME_RATE = 60;

//paddle constants
const int PADDLE_WIDTH = 10;
const int PADDLE_HEIGHT = 100;
const float PADDLE_SPEED = 0.5;

const sf::Vector2f PLAYER_INITIAL_POS = sf::Vector2f(50, (SCREEN_HEIGHT / 2) - PADDLE_HEIGHT / 2);
const sf::Vector2f COMP_INITIAL_POS = sf::Vector2f(750 - PADDLE_WIDTH, (SCREEN_HEIGHT / 2) - PADDLE_HEIGHT / 2);

//ball constants
const int BALL_DIAMETER = 20;
const int BALL_RADIUS = BALL_DIAMETER / 2;
const float BALL_SPEED = 0.5;
const sf::Vector2f BALL_INITIAL_POS = sf::Vector2f((SCREEN_WIDTH / 2) - BALL_RADIUS, (SCREEN_HEIGHT / 2) - BALL_RADIUS);

#include <iostream>
#include <cmath>

using namespace std;