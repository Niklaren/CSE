#pragma once

#include <SFML/Graphics.hpp>

#include "Option.h"
#include <vector>
#include <string>

// for every action availabe to the player we must create an option
// we should do this in code if possible

class Menu
{
	std::vector<Option> options; // vector not strictly necessarry
	
	sf::Texture texture;
	sf::IntRect menuRect;

public:
	Menu();
	~Menu();

	void AddOption(string name, int x, int y, int length); //position too??? probably calculate later?
	void Menu::Draw(sf::RenderWindow&);
	int Get_NumberOfOptions();

	bool OptionClicked(float mouseX, float mouseY, string &name);

	void Reset();
};

