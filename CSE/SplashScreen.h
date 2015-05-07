#pragma once

#include <SFML/Graphics.hpp>

#include "Input.h"

enum State { menu, game, close };

// splash screen can choose to exit or play game
class SplashScreen
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	Input* input;
public:
	SplashScreen(Input*);
	~SplashScreen();

	State Update();

	void Redraw(sf::RenderWindow&);
};

