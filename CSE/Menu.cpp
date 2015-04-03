#include "stdafx.h"
#include "Menu.h"



Menu::Menu()
{
	menuRect.left = 550;
	menuRect.top = 0;
	
	AddOption("OK",			0, 0, 1);
	AddOption("A",			2, 0, 1);
	AddOption("B",			3, 0, 1);
	AddOption("Hug",		0, 1, 1);
	AddOption("Apologize",	1, 1, 3);
	AddOption("Greet",		0, 2, 2);
	AddOption("Joke",		0, 3, 2);
	AddOption("Insult",		2, 3, 2);
	//AddOption("Intervene",	1, 4, 3);

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

bool Menu::HandleMenu(Input input)
{
	/*if (input.LMjustReleased()){
		string optionName = "";
		if (menu.OptionClicked(input.MouseX, input.MouseY, optionName)){
			if (optionName == "A" && actionName != ""){
				Protagonist->Plan(actionName, Char1);
				executePlans = true;
				actionName = "";
				Protagonist->menu.Reset();
			}
			else if (optionName == "B" && actionName != ""){
				Protagonist->Plan(actionName, Char2);
				executePlans = true;
				actionName = "";
				Protagonist->menu.Reset();
			}
			else if (optionName == "OK"){
				executePlans = true;
				actionName = "";
				menu.Reset();
			}
			else if (optionName == "Intervene"){
				Protagonist->Plan(optionName, Char1, Char2);
				executePlans = true;
				actionName = "";
				menu.Reset();
			}
			else if (optionName != "OK" && optionName != "A" && optionName != "B"){
				actionName = optionName;
			}
		}
	}*/
	return false;
}