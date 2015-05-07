// CSE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>

#include <SFML/Graphics.hpp>

#include "SplashScreen.h"
#include "Engine.h"
#include "Input.h"

Input* input = new Input();
Engine* engine;
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
	
	//bool gameEnded = false;
	state = menu;

	// small instructions we can show on the console
	std::cout << "Thanks for playing" << std::endl;
	std::cout << "This is an interactive story game where the goal is to experience the story\nhowever you please.\n" << std::endl;

	std::cout << "To act within the world choose an action from the menu in the top right." << std::endl;
	std::cout << "Yellow actions can be performed right away." << std::endl;
	std::cout << "Purple actions require a target, you can select from targets in the same\nlocation as you from the top row. (No available targets in the first scene)." << std::endl;
	std::cout << "To clear your selection press the red X." << std::endl;
	std::cout << "To lock in your choice and perform the action press OK" << std::endl;
	std::cout << "At any time you have the option TO NOT ACT by choosing no options\nand only pressing OK" << std::endl;
	std::cout << "You will see the results of actions in the text box along the bottom" << std::endl;
	std::cout << "There will be times when you cannot act, to progess press OK." << std::endl;

	std::cout << "\nbest of luck and we apologize in advances for any bugs, errors or misspellings." << std::endl;
	// but we'll just hide the console
	FreeConsole();
	
	int attempt = 0;	// calculate the number of playthroughs

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
					HandleInput(LDown);
				if (event.mouseButton.button == sf::Mouse::Right)
				{
				}
			}
			if (event.type == sf::Event::MouseButtonReleased){
				if (event.mouseButton.button == sf::Mouse::Left)
					HandleInput(LUp);
				if (event.mouseButton.button == sf::Mouse::Right)
				{
				}
			}
			if (event.type == sf::Event::MouseMoved)
				HandleInput(MouseMove, float(event.mouseMove.x), float(event.mouseMove.y));
		}

		// FSM for game/menu/exit
		if (state == menu)
		{
			splash.Redraw(window);
			state = splash.Update();

			if (state == game){
				attempt++;
				engine = new Engine(input, attempt);

			}
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
