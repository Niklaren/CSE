// CSE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <SFML/Graphics.hpp>

#include "SplashScreen.h"
#include "Engine.h"
#include "Input.h"

Input* input = new Input();
Engine* engine = new Engine(input);
SplashScreen splash(input);

//sf::RenderWindow window;

State state;

void HandleInput(InputType inputType)
{
	assert(inputType == LDown || inputType == LUp);
	if (inputType == LDown) input->handleLMousePressed();
	else if (inputType == LUp) input->handleLMouseReleased();
}
void HandleInput(InputType inputType, float x, float y)
{
	assert(inputType == MouseMove);
	input->MouseX = x;
	input->MouseY = y;
}

int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "CSE", sf::Style::Titlebar | sf::Style::Close);
	
	//window.setPosition(sf::Vector2i(10, 50));
	//window.setSize(sf::Vector2u(640, 480));
	//window.setTitle("CSE");

	//bool gameEnded = false;
	state = menu;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//input
			if (event.type == sf::Event::KeyPressed)
			{
			}
			if (event.type == sf::Event::KeyReleased)
			{
			}
			if (event.type == sf::Event::MouseButtonPressed){
				if (event.mouseButton.button == sf::Mouse::Left)
					//engine->HandleInput(LDown);
					HandleInput(LDown);
				if (event.mouseButton.button == sf::Mouse::Right)
				{
				}
			}
			if (event.type == sf::Event::MouseButtonReleased){
				if (event.mouseButton.button == sf::Mouse::Left)
					//engine->HandleInput(LUp);
					HandleInput(LUp);
				if (event.mouseButton.button == sf::Mouse::Right)
				{
				}
			}
			if (event.type == sf::Event::MouseMoved)
				//engine->HandleInput(MouseMove, float(event.mouseMove.x), float(event.mouseMove.y));
				HandleInput(MouseMove, float(event.mouseMove.x), float(event.mouseMove.y));
		}

		if (state == menu)
		{
			splash.Redraw(window);
			state = splash.Update();

			if (state == game)
				engine = new Engine(input);
		}
		
		else if (state == game){

			if (engine->Operate())
				state = menu;

			engine->Redraw(window);
		}

		else if (state == close){
			window.close();
		}

		input->update();
	}
	
	return 0;
}
