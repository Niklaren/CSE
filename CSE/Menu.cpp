#include "stdafx.h"
#include "Menu.h"

#include "Action.h"

Menu::Menu()
{
	menuRect.left = 550;
	menuRect.top = 0;
	
	AddOption("OK", Type_OK,				0, 0, 1);
	AddOption("Clear", Type_None,			1, 0, 1);
	
	AddOption("Wolf", Type_Character,		2, 0, 1);
	AddOption("Lumberjack", Type_Character,	3, 0, 1);
	AddOption("Grandma", Type_Character,	4, 0, 1);

	AddOption("forest", Type_Location,		0, 1, 1);
	AddOption("cabin", Type_Location,		1, 1, 1);
	AddOption("lodge", Type_Location,		2, 1, 1);
	AddOption("path", Type_Location,		3, 1, 1);

	AddOption("Travel", Type_ActLocation,	0, 2, 2);
	AddOption("Go Home", Type_Act0Target,	2, 2, 2);
	AddOption("Observe", Type_Act0Target,	0, 3, 2);
	AddOption("Stray Off Path", Type_Act0Target, 2, 3, 3);
	AddOption("Walk Path", Type_Act0Target, 0, 4, 2);

	AddOption("Greet", Type_Act1Target,		0, 5, 2);
	AddOption("Answer", Type_Act1Target,	2, 5, 2);

	AddOption("Request Entry", Type_Act1Target, 0, 6, 3);
	AddOption("Give Food", Type_Act1Target, 3, 6, 2);
	//AddOption("Hug", Type_Act1Target,		0, , 1);
	//AddOption("Apologize", Type_Act1Target, 1, 4, 3);
	
	//AddOption("Joke", Type_Act1Target,		2, 5, 2);
	//AddOption("Insult", Type_Act1Target,	2, 6, 2);
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

void Menu::Reset(vector<string> availableActions, vector<string> availableLocations, vector<string> availableCharacters)
{
	selected_act0Target = selected_act1Target = selected_actLocation = selected_location = selected_character = false;
	optionName = locName = charName = "";

	for (int optionNum = 0; optionNum < Get_NumberOfOptions(); optionNum++){
		options[optionNum].SetAvailable();
		if (options[optionNum].GetType() >= Type_Act0Target){ // if the option is an action
			options[optionNum].SetUnavailable();
			for (unsigned i = 0; i < availableActions.size(); i++){
				if (options[optionNum].GetName() == availableActions[i])
					options[optionNum].SetAvailable();
			}
		}
		else if (options[optionNum].GetType() == Type_Location){ // if the option is an Location
			options[optionNum].SetUnavailable();
			for (unsigned i = 0; i < availableLocations.size(); i++){
				if (options[optionNum].GetName() == availableLocations[i])
					options[optionNum].SetAvailable();
			}
		}
		else if (options[optionNum].GetType() == Type_Character){ // if the option is an Location
			options[optionNum].SetUnavailable();
			for (unsigned i = 0; i < availableCharacters.size(); i++){
				if (options[optionNum].GetName() == availableCharacters[i])
					options[optionNum].SetAvailable();
			}
		}
	}
}

void Menu::DeselectAll()
{
	selected_act0Target = selected_act1Target = selected_actLocation = selected_location = selected_character = false;
	optionName = locName = charName = "";

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
				DeselectAll();
			}
			if (options[oIndex].GetType() == Type_ActLocation){
				DeselectAll();
				options[oIndex].SetSelected();
				selected_actLocation = true;
				optionName = options[oIndex].GetName();
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
			if (options[oIndex].GetType() == Type_Location){
				if (selected_actLocation){
					options[oIndex].SetSelected();
					selected_location = true;
					locName = options[oIndex].GetName();
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
				else if (selected_actLocation){
					if (selected_location){
						option = optionName;
						target = locName;
						DeselectAll();
						return true;
					}
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