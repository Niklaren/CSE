#pragma once

#include <SFML/Graphics.hpp>

#include "Input.h"
#include "Option.h"
//#include "Player_Actor.h"

#include <vector>
#include <string>

class Player_Actor;
class Actor;
class NPC_Actor;
class Action;

// The menu displays all the options that the player can choose to act within the story
class Menu
{
	std::vector<Option> options;

	sf::Texture texture;
	sf::IntRect menuRect;

	string optionName, locName, charName;
	bool selected_act0Target, selected_act1Target, selected_actLocation, selected_location, selected_character, selected_character2;
public:
	Menu();
	~Menu();

	void AddOption(string name, OptionType t, int width, int x = 0, int y = 0);
	int Get_NumberOfOptions(){ return options.size(); }

	void Menu::Draw(sf::RenderWindow&);
	
	bool OptionClicked(float mouseX, float mouseY, int& option_index);

	void Reset(vector<string> availableActions, vector<string> availableLocations, vector<string> availableTargets);
	void DeselectAll();
	void AllUnavailable();

	bool HandleMenu(Input input, string &action, string &target);
	void BuildMenu();

};

