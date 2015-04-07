#include "stdafx.h"
#include "Menu.h"

#include "Action.h"

Menu::Menu()
{
	menuRect.left = 550;
	menuRect.top = 0;
	
	AddOption("OK", Type_OK,				0, 0, 1);
	AddOption("A", Type_Character,			2, 0, 1);
	AddOption("B", Type_Character,			3, 0, 1);

	AddOption("Do Nothing", Type_Act0Target, 0, 2, 3);

	AddOption("Hug", Type_Act1Target,		0, 4, 1);
	AddOption("Apologize", Type_Act1Target, 1, 4, 3);
	AddOption("Greet", Type_Act1Target,		0, 5, 2);
	AddOption("Joke", Type_Act1Target,		2, 5, 2); // 0 or 1 ?
	AddOption("Insult", Type_Act1Target,	2, 6, 2);
	//AddOption("Intervene",	1, 4, 3);

	selected_act0Target = selected_act1Target = selected_character = false;
}

Menu::~Menu()
{

}

void Menu::AddOption(string name, OptionType t, int x_, int y_, int width_)
{
	// some code to work out its position here
	//pos = options.top().pos + length
	//if( pos> END_OF_LINE)
	//posy = options.top().pos + height
	//posx = START_OF_LINE;


	Option option(name, t, menuRect, x_, y_, width_);
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

bool Menu::OptionClicked(float mouseX_, float mouseY_, int& o)
{
	// for every options from the menu
	for (int optionNum = 0; optionNum < Get_NumberOfOptions(); optionNum++){
		if (options[optionNum].IsClicked(mouseX_, mouseY_)){
			o = optionNum;
			return true;
		}
	}
	return false;
}

void Menu::Reset(vector<string> availableActions)
{
	selected_act0Target = selected_act1Target = selected_character = false;
	optionName = charName = "";

	for (int optionNum = 0; optionNum < Get_NumberOfOptions(); optionNum++){
		options[optionNum].SetAvailable();
		if (options[optionNum].GetType() >= Type_Act0Target){ // if the option is an action
			options[optionNum].SetUnavailable();
			for (unsigned i = 0; i < availableActions.size(); i++){
				if (options[optionNum].GetName() == availableActions[i])
					options[optionNum].SetAvailable();
			}
		}
	}
}

void Menu::DeselectAll()
{
	selected_act0Target = selected_act1Target = selected_character = false;
	optionName = charName = "";

	for (int optionNum = 0; optionNum < Get_NumberOfOptions(); optionNum++){
		if (options[optionNum].IsSelected())
			options[optionNum].SetAvailable();
	}
}

bool Menu::HandleMenu(Input input, string &option, string &target)
{
	int oIndex;
	if (input.LMjustReleased()){
		if (OptionClicked(input.MouseX, input.MouseY, oIndex)){

			// switch statement better?
			if (options[oIndex].GetType() == Type_None){ // no longer needed
				return false;
			}
			if (options[oIndex].GetType() == Type_Act0Target){
				DeselectAll();
				options[oIndex].SetSelected();
				selected_act0Target = true;
				optionName = options[oIndex].GetName();
			}
			if (options[oIndex].GetType() == Type_Act1Target){
				DeselectAll();
				options[oIndex].SetSelected();
				selected_act1Target = true;
				optionName = options[oIndex].GetName();
			}
			if (options[oIndex].GetType() == Type_Character){
				if (selected_act1Target){
					options[oIndex].SetSelected();
					selected_character = true;
					charName = options[oIndex].GetName();
				}
				if (selected_act0Target){
					;// this action does not require a target
				}
			}
			if (options[oIndex].GetType() == Type_OK){
				if (selected_act0Target){
					option = optionName;
					DeselectAll();
					return true;
				}
				else if (selected_act1Target){
					if (selected_character){
						option = optionName;
						target = charName;
						DeselectAll();
						return true;
					}
					else
						;//please select a target
				}
				else if (selected_act2Target){
					;
				}
				else{
					DeselectAll();
					return true;
				}
			}
		}
	}
		
	return false;


		/*if (OptionClicked(input.MouseX, input.MouseY, optionName)){
			if (optionName == "A" && actionName != ""){
				protagonist->Plan(actionName, Char1);
				executePlans = true;
				actionName = "";
				protagonist->menu.Reset();
			}
			else if (optionName == "B" && actionName != ""){
				protagonist->Plan(actionName, Char2);
				executePlans = true;
				actionName = "";
				protagonist->menu.Reset();
			}
			else if (optionName == "OK"){
				executePlans = true;
				actionName = "";
				menu.Reset();
			}
			else if (optionName == "Intervene"){
				protagonist->Plan(optionName, Char1, Char2);
				executePlans = true;
				actionName = "";
				menu.Reset();
			}
			else if (optionName != "OK" && optionName != "A" && optionName != "B"){
				actionName = optionName;
			}
		}*/

}