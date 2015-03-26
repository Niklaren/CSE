#pragma once

#include <SFML/Graphics.hpp>

#include <string>

using namespace std;

// may wish to later change this to pictures, and only show text
// when the mouse hovers over the option.

class Option
{
	//int leftX, rightX, topY, botY;
	//RECT optionRect;
	sf::IntRect textureRect;
	sf::IntRect optionRect;
	string name;

	sf::Texture texture;
	sf::Sprite sprite;
	//HBITMAP bitmap;

public:
	Option(string name_, sf::IntRect menu, int x_, int y_, int width_);
	~Option();

	bool Draw(sf::RenderWindow&);

	bool IsClicked(float cursor_x, float cursor_y);
	bool pressed;

	string GetName(){ return name; }
	//sf::Text GetText() { return text; }
};

