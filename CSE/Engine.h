#pragma once

#include <SFML/Graphics.hpp>

#include "Action.h"
#include "HistoryBook.h"
#include "WorldState.h"
#include "Actor.h"
#include "NPC_Actor.h"
#include "Player_Actor.h"
#include "DramaManager.h"
#include "Menu.h"

#include "Input.h"

#include <queue>
#include <assert.h>

enum InputType {LDown, LUp, KeyDown, KeyUp, MouseMove};

#define MAX_ACTORS 4

class Engine
{
protected:
	
	Menu menu;
	Input input;
	HistoryBook historyBook;

	DramaManager *Fate = new DramaManager("fate", historyBook);
	Player_Actor *Protagonist = new Player_Actor("protagonist", historyBook);
	NPC_Actor *Char1 = new NPC_Actor("char1.txt", historyBook);
	NPC_Actor *Char2 = new NPC_Actor("char2.txt", historyBook);

	//DramaManager cDerived;
	//Actor &rBase = cDerived;

	std::queue<Action> plans;
	Actor *actors[MAX_ACTORS];	//Array of the 4 actors in the scene.
	
	sf::Clock clock;
	sf::Time time;
	bool executePlans = true;
	string actionName;

	sf::Sprite stageSprite;
	sf::Texture stageTexture;

public:
	Engine();
	~Engine();

	void Operate();

	void GetUserInput();

	void HandleInput(InputType);
	void HandleInput(InputType, float x, float y);
	//void HandleInput(InputType,LPARAM);
	//void HandleInput(InputType,WPARAM);

	void Redraw(sf::RenderWindow&);
	//bool BlitBitmap(HBITMAP hBitmap, HDC hWinDC, int x, int y);
};

