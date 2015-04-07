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

// for every action availabe to the player we must create an option
// we should do this in code if possible

class Menu
{
	std::vector<Option> options; // vector not strictly necessarry
	//std::vector<Option> ActionOptions;
	
	sf::Texture texture;
	sf::IntRect menuRect;

	string optionName, charName;
	bool selected_act0Target, selected_act1Target, selected_act2Target, selected_character, selected_character2;
public:
	Menu();
	~Menu();

	void AddOption(string name, OptionType t, int x, int y, int length); //position too??? probably calculate later?
	void Menu::Draw(sf::RenderWindow&);
	int Get_NumberOfOptions(){ return options.size(); }

	bool OptionClicked(float mouseX, float mouseY, int& option_index);

	void Reset(vector<string> availableActions);
	void DeselectAll();

	bool HandleMenu(Input input, string &action, string &target);


};

