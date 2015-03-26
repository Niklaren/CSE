#include "stdafx.h"
#include "Menu.h"



Menu::Menu()
{
	menuRect.left = 550;
	menuRect.top = 0;
	
	AddOption("OK",0, 0, 1);
	AddOption("A", 2, 0, 1);
	AddOption("B", 3, 0, 1);
	AddOption("Hug", 0, 1, 1);
	AddOption("Apologize", 1, 1, 3);
	AddOption("Punch", 0, 2, 2);
	AddOption("Insult", 2, 2, 2);
	AddOption("Intervene", 0, 3, 2);

}

Menu::~Menu()
{

}

void Menu::AddOption(string name, int x_, int y_, int width_)
{
	// some code to work out its position here
	//pos = options.top().pos + length
	//if( pos> END_OF_LINE)
	//posy = options.top().pos + height
	//posx = START_OF_LINE;


	Option option(name, menuRect, x_, y_, width_);
	options.push_back(option);
}

void Menu::Draw(sf::RenderWindow &window)
{
	// for every options from the menu
	for (int optionNum = 0; optionNum < Get_NumberOfOptions(); optionNum++){
		// draw option
		options[optionNum].Draw(window);
		//window.draw(options[optionNum].GetText());
	}
}

int Menu::Get_NumberOfOptions()
{
	return options.size();
}

bool Menu::OptionClicked(float mouseX_, float mouseY_, string &name)
{
	// for every options from the menu
	for (int optionNum = 0; optionNum < Get_NumberOfOptions(); optionNum++){
		if (options[optionNum].IsClicked(mouseX_, mouseY_)){
			name = options[optionNum].GetName();
			options[optionNum].pressed = true;
			return true;
		}
	}
	return false;
}

void Menu::Reset()
{
	for (int optionNum = 0; optionNum < Get_NumberOfOptions(); optionNum++){
		options[optionNum].pressed = false;
	}
}