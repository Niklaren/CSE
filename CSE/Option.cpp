#include "stdafx.h"
#include "Option.h"
#include <string>
#include <iostream>


#define WIDTH_PER_CHAR 15
#define MENU_ELEMENT_SIZE 50
//#define 

Option::Option(string name_, sf::IntRect menu, int x_, int y_, int width_)
{
	int x = x_ * MENU_ELEMENT_SIZE;
	int y = y_ * MENU_ELEMENT_SIZE;
	int width = width_ * MENU_ELEMENT_SIZE;
	
	sf::IntRect textureRect_(x, y, width, MENU_ELEMENT_SIZE);
	textureRect = textureRect_;
	if (!texture.loadFromFile("menu.png", textureRect))
	{
		//error
		std::cout << "error" << std::endl;
	}

	name = name_;
	optionRect.left = menu.left + x;
	optionRect.top = menu.top + y;
	optionRect.width = width;
	optionRect.height = MENU_ELEMENT_SIZE;

	pressed = false;

	//int width = name.size() * WIDTH_PER_CHAR;


	//TextOut(hdc, leftX, topY, action.c_str, action.size);

	//if (!font.loadFromFile("arial.ttf"))
	//{	/*error;*/	}
	//text.setFont(font);
	//text.setString(name);
	//text.setCharacterSize(24);
	//text.setPosition(sf::Vector2f((float)x_,(float)y_));
}


Option::~Option()
{
}

bool Option::Draw(sf::RenderWindow &window)
{
	//DrawTextW(hdc, name.c_str(), name.length(), &optionRect, DT_CENTER);
	if (pressed)
		texture.loadFromFile("menupressed.png", textureRect);
	else
		!texture.loadFromFile("menu.png", textureRect);

	
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f((float)optionRect.left, (float)optionRect.top));
	window.draw(sprite);

	sf::Font tfont;
	tfont.loadFromFile("arial.ttf");
	sf::Text ttext;
	ttext.setFont(tfont);
	ttext.setString(name);
	ttext.setCharacterSize(24);
	ttext.setPosition(sf::Vector2f(optionRect.left+5, optionRect.top+10));
	window.draw(ttext);
	
	return true;
}

bool Option::IsClicked(float cursor_x, float cursor_y)		//checks if cursor is in screen region
{
	// if cursor is in screen region
	//int mouseX = sf::Mouse::getPosition(window);
	if ((cursor_x > optionRect.left) && (cursor_x < (optionRect.left + optionRect.width))){	// if in the x bounds
		if ((cursor_y <(optionRect.top + optionRect.height)) && (cursor_y > optionRect.top)){	// and y bounds
			std::cout << name + " clicked" << std::endl;
			return true;
		}
	}
	return false;
}