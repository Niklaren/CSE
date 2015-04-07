#pragma once

#include <SFML/Graphics.hpp>

#include <string>

using namespace std;

enum OptionType { Type_None, Type_OK, Type_Character, Type_Location, Type_Act0Target, Type_Act1Target, Type_ActLocation };
enum OptionState { Unavailable, Available, Selected } ;

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

	OptionState state;
	OptionType type;

public:
	Option(string name_, OptionType t, sf::IntRect menu, int x_, int y_, int width_);
	Option();
	~Option();

	bool Draw(sf::RenderWindow&);

	bool IsClicked(float cursor_x, float cursor_y);
	//bool pressed;

	string GetName(){ return name; }
	//sf::Text GetText() { return text; }

	void SetUnavailable() { state = Unavailable; }
	void SetAvailable() { state = Available; }
	void SetSelected() { state = Selected; }
	bool IsSelected() { if (state == Selected){ return true; } return false; }
	OptionType GetType() { return type; }
};

