// CSE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <SFML/Graphics.hpp>

#include "Engine.h"
#include "Input.h"

//Input input;
Engine engine;

//sf::RenderWindow window;

int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow window(sf::VideoMode(750, 400), "CSE");
	
	//window.setPosition(sf::Vector2i(10, 50));
	//window.setSize(sf::Vector2u(640, 480));
	//window.setTitle("CSE");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{	window.close();	}

			//input
			if (event.type == sf::Event::KeyPressed)
			{		}
			if (event.type == sf::Event::KeyReleased)
			{}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{	engine.HandleInput(LDown);	}
				if (event.mouseButton.button == sf::Mouse::Right)
				{}
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{	engine.HandleInput(LUp);	}
				if (event.mouseButton.button == sf::Mouse::Right)
				{}
			}
			if (event.type == sf::Event::MouseMoved)
			{
				engine.HandleInput(MouseMove, float(event.mouseMove.x), float(event.mouseMove.y));
			}
		}

		engine.Operate();
		
		engine.Redraw(window);

	}
	
	return 0;
}
