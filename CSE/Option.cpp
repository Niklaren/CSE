#include "stdafx.h"
#include "Option.h"
#include <string>
#include <iostream>

//#define WIDTH_PER_CHAR 15

// Initialize an option based on its position and width (and type)
Option::Option(string name_, OptionType t, sf::IntRect menu, int x_, int y_, int width_)
{
	int x = x_ * MENU_ELEMENT_SIZE;
	int y = y_ * MENU_ELEMENT_SIZE;
	int width = width_ * MENU_ELEMENT_SIZE;
	if (t == Type_Act0Target){
		x = 0;
		y = (width_+1) * MENU_ELEMENT_SIZE;
		width = width_ * MENU_ELEMENT_SIZE;
	}
	else if (t == Type_Act1Target){
		x = (5 - width_) * MENU_ELEMENT_SIZE;
		y = (6 - width_) * MENU_ELEMENT_SIZE;
		width = width_ * MENU_ELEMENT_SIZE;
	}

	sf::IntRect textureRect_(x, y, width, MENU_ELEMENT_SIZE);
	textureRect = textureRect_;
	if (!texture.loadFromFile("Assets/menu.png", textureRect))
	{
		//error
		std::cout << "error" << std::endl;
	}

	name = name_;
	type = t;
	state = Unavailable;

	optionRect.left = menu.left + x;
	optionRect.top = menu.top + y;
	optionRect.width = width;
	optionRect.height = MENU_ELEMENT_SIZE;
}

Option::Option()
{
}

Option::~Option()
{
}

void Option::SetPosition(sf::IntRect menu, int x, int y)
{
	optionRect.left = menu.left + (x*MENU_ELEMENT_SIZE);
	optionRect.top = menu.top + (y*MENU_ELEMENT_SIZE);
	optionRect.width = textureRect.width;
	optionRect.height = MENU_ELEMENT_SIZE;
}

bool Option::Draw(sf::RenderWindow &window)
{
	// load the correct menu asset
	if (state == Selected)
		texture.loadFromFile("Assets/menupressed.png", textureRect);
	if (state == Available)
		texture.loadFromFile("Assets/menu.png", textureRect);
	if (state == Locked ||	state == Unavailable || state == OnHold)
		texture.loadFromFile("Assets/menuUnavailable.png", textureRect);

	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f((float)optionRect.left, (float)optionRect.top));
	window.draw(sprite);

	// write text to display the name of named options
	if (type >= Type_Act0Target){
		sf::Font tfont;
		tfont.loadFromFile("Assets/arial.ttf");
		sf::Text ttext;
		ttext.setFont(tfont);
		ttext.setString(name);
		ttext.setCharacterSize(20);
		ttext.setPosition(sf::Vector2f(optionRect.left + 3, optionRect.top + 10));
		window.draw(ttext);
	}
	
	return true;
}

bool Option::IsClicked(float cursor_x, float cursor_y)		//checks if cursor is in screen region
{
	if (state == Unavailable)
		return false;

	if ((cursor_x > optionRect.left) && (cursor_x < (optionRect.left + optionRect.width))){	// if in the x bounds
		if ((cursor_y <(optionRect.top + optionRect.height)) && (cursor_y > optionRect.top)){	// and y bounds
			//std::cout << name + " clicked" << std::endl;
			return true;
		}
	}
	return false;
}