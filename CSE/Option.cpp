#include "stdafx.h"
#include "Option.h"
#include <string>
#include <iostream>


#define WIDTH_PER_CHAR 15
#define MENU_ELEMENT_SIZE 50
//#define 

Option::Option(string name_, OptionType t, sf::IntRect menu, int x_, int y_, int width_)
{
	int x = x_ * MENU_ELEMENT_SIZE;
	int y = y_ * MENU_ELEMENT_SIZE;
	int width = width_ * MENU_ELEMENT_SIZE;
	
	sf::IntRect textureRect_(x, y, width, MENU_ELEMENT_SIZE);
	textureRect = textureRect_;
	if (!texture.loadFromFile("Assets/menu.png", textureRect))
	{
		//error
		std::cout << "error" << std::endl;
	}

	name = name_;
	optionRect.left = menu.left + x;
	optionRect.top = menu.top + y;
	optionRect.width = width;
	optionRect.height = MENU_ELEMENT_SIZE;

	type = t;
	state = Unavailable;
	//pressed = false;

	//int width = name.size() * WIDTH_PER_CHAR;


	//TextOut(hdc, leftX, topY, action.c_str, action.size);

	//if (!font.loadFromFile("arial.ttf"))
	//{	/*error;*/	}
	//text.setFont(font);
	//text.setString(name);
	//text.setCharacterSize(24);
	//text.setPosition(sf::Vector2f((float)x_,(float)y_));
}

Option::Option()
{
}

Option::~Option()
{
}

bool Option::Draw(sf::RenderWindow &window)
{
	//DrawTextW(hdc, name.c_str(), name.length(), &optionRect, DT_CENTER);
	if (state == Selected)
		texture.loadFromFile("Assets/menupressed.png", textureRect);
	if (state == Available)
		texture.loadFromFile("Assets/menu.png", textureRect);
	if (state == Unavailable)
		texture.loadFromFile("Assets/menuUnavailable.png", textureRect);


	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f((float)optionRect.left, (float)optionRect.top));
	window.draw(sprite);

	if (type >= Type_Act0Target){
		sf::Font tfont;
		tfont.loadFromFile("Assets/arial.ttf");
		sf::Text ttext;
		ttext.setFont(tfont);
		ttext.setString(name);
		ttext.setCharacterSize(20);
		ttext.setPosition(sf::Vector2f(optionRect.left + 5, optionRect.top + 10));
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
			std::cout << name + " clicked" << std::endl;
			return true;
		}
	}
	return false;
}