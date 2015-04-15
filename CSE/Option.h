#pragma once

#include <SFML/Graphics.hpp>

#include <string>

using namespace std;

#define MENU_ELEMENT_SIZE 50
enum OptionType { Type_None, Type_OK, Type_Character, Type_Location, Type_Act0Target, Type_Act1Target, Type_ActLocation };
enum OptionState { Locked, Unavailable, Available, Selected, OnHold } ;

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
	//Option(string name_, OptionType t, sf::IntRect menu, int width_);
	Option();
	~Option();

	void SetPosition(sf::IntRect menu, int x, int y);

	bool Draw(sf::RenderWindow&);

	bool IsClicked(float cursor_x, float cursor_y);
	//bool pressed;

	string GetName(){ return name; }
	//sf::Text GetText() { return text; }

	void SetLocked() { state = Locked; }
	void SetUnavailable() { state = Unavailable; }
	void SetAvailable() { state = Available; }
	void SetSelected() { state = Selected; }
	void SetOnHold() { state = OnHold; }
	bool IsSelected() { if (state == Selected){ return true; } return false; }
	bool IsAvailable() { if (state == Available){ return true; } return false; }
	OptionType GetType() { return type; }

	int GetWidth() { return (textureRect.width / MENU_ELEMENT_SIZE); }
};

