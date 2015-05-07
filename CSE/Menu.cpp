#include "stdafx.h"
#include "Menu.h"

#include "Action.h"

Menu::Menu()
{
	menuRect.left = 550;
	menuRect.top = 0;
	
	AddOption("OK", Type_OK,					1,		0, 0);
	AddOption("Clear", Type_None,				1,		1, 0);
	
	AddOption("Wolf", Type_Character,			1,		2, 0);
	AddOption("Lumberjack", Type_Character,		1,		3, 0);
	AddOption("Grandma", Type_Character,		1,		4, 0);

	/*AddOption("forest", Type_Location,		1,		0, 1);
	AddOption("cabin", Type_Location,			1,		1, 1);
	AddOption("lodge", Type_Location,			1,		2, 1);
	AddOption("path", Type_Location,			1,		3, 1);*/

	//AddOption("Travel", Type_ActLocation,	0, 2, 2);
	AddOption("Go Home", Type_Act0Target,		2);
	AddOption("Observe", Type_Act0Target,		2);
	AddOption("Stray Off Path", Type_Act0Target,3);
	AddOption("Walk Path", Type_Act0Target,		2);
	AddOption("Go To Lodge", Type_Act0Target,	3);

	AddOption("Greet", Type_Act1Target,			2);
	AddOption("Answer", Type_Act1Target,		2);
	AddOption("Ignore", Type_Act1Target,		2);
	AddOption("Walk Away", Type_Act0Target,		2);
	AddOption("Flee", Type_Act0Target,			2);
	AddOption("Ask Directions", Type_Act1Target,3);
	AddOption("Turn Back", Type_Act0Target,		3);
	AddOption("Continue Forward", Type_Act0Target, 4);
	AddOption("Pick Flowers", Type_Act0Target,	3);
	AddOption("Give Flowers", Type_Act1Target,	3);
	AddOption("Request Escort", Type_Act1Target,4);
	AddOption("Thank", Type_Act1Target,			2);

	AddOption("Knock Door", Type_Act0Target,	3);
	AddOption("Enter Lodge", Type_Act0Target,	2);
	AddOption("Give Food", Type_Act1Target,		2);
	AddOption("Apologize", Type_Act1Target,		2);
	AddOption("Hug", Type_Act1Target,			1);
	

	//AddOption("Hug", Type_Act1Target,		0, , 1);
	//AddOption("Joke", Type_Act1Target,		2, 5, 2);
	//AddOption("Insult", Type_Act1Target,	2, 6, 2);
	//AddOption("Intervene",	1, 4, 3);

	selected_act0Target = selected_act1Target = selected_character = false;
}

Menu::~Menu()
{

}

// add options to the possible options
void Menu::AddOption(string name, OptionType t, int width_, int x_, int y_)
{
	//Option option(name, t, menuRect, width_);
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

// checks if an option is clicked and edits 'o' (option) accordingly
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
		if (options[optionNum].GetType() <= Type_OK)	// ok & clear available by default
			options[optionNum].SetAvailable();
		else if (options[optionNum].GetType() >= Type_Act0Target){ // if the option is an action
			options[optionNum].SetUnavailable();
			for (unsigned i = 0; i < availableActions.size(); i++){
				if (options[optionNum].GetName() == availableActions[i])
					options[optionNum].SetAvailable();
			}
		}
		else if (options[optionNum].GetType() == Type_Location){ // if the option is a Location
			options[optionNum].SetUnavailable();
			for (unsigned i = 0; i < availableLocations.size(); i++){
				if (options[optionNum].GetName() == availableLocations[i])
					options[optionNum].SetAvailable();
			}
		}
		else if (options[optionNum].GetType() == Type_Character){ // if the option is a character
			options[optionNum].SetUnavailable();
			for (unsigned i = 0; i < availableCharacters.size(); i++){
				if (options[optionNum].GetName() == availableCharacters[i])
					options[optionNum].SetAvailable();
			}
		}
	}

	BuildMenu();
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

void Menu::AllUnavailable()
{
	for (int optionNum = 0; optionNum < Get_NumberOfOptions(); optionNum++){
		options[optionNum].SetUnavailable();
		if (options[optionNum].GetType() == Type_OK){
			options[optionNum].SetAvailable();
		}
	}
}

// handle menu inputs and return true if a selection has been made
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
			/*if (options[oIndex].GetType() == Type_Location){
				//if (selected_actLocation){
					options[oIndex].SetSelected();
					selected_location = true;
					locName = options[oIndex].GetName();
				//}
			}*/
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
				else if (selected_location){
						option = "Travel";
						target = locName;
						DeselectAll();
						return true;
				}
				else{
					DeselectAll();
					return true;
				}
			}
		}
	}
		
	return false;
}

// move the otions so that avaialable ones appear onscreen and unavailable ones do not.
void Menu::BuildMenu()
{
	int x = 0;
	int y = 2;

	for (int oNum = 0; oNum < Get_NumberOfOptions(); oNum++){
		if (options[oNum].GetType() >= Type_Act0Target){
			if (options[oNum].IsAvailable()){
				if (x + options[oNum].GetWidth() > 5)
				{
					x = 0;
					y += 1;
				}
				options[oNum].SetPosition(menuRect, x, y);
				x += options[oNum].GetWidth();
			}
			else
			{
				options[oNum].SetPosition(menuRect, 6, 0);
			}
		}
	}
}