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
#include "Planner.h"

#include "Input.h"

#include <queue>
#include <assert.h>

enum InputType {LDown, LUp, KeyDown, KeyUp, MouseMove};

#define MAX_ACTORS 4
// would likely be better to have them start at 0 maybe? then have NPC_MAX
// problem with this is it would put fate as no longer first. so for now:
#define NPC_ACTOR_START 2
//#define NPC_ACTOR_END 4

class Engine
{
protected:
	
	Input input;
	HistoryBook historyBook;
	Planner planner;
	WorldState worldstate;
	Menu menu;

	Stage* offStage = new Stage("stage.png", "offStage");
	Stage* camp = new Stage("camp.bmp", "camp");
	Stage* path = new Stage("path.png", "path");
	Stage* forest = new Stage("forest.png", "forest");
	Stage* cabin = new Stage("huntsmanCabin.png", "cabin");
	Stage* lodge = new Stage("grandmasLodge.png", "lodge");
	

	Player_Actor *Protagonist = new Player_Actor("You", path, historyBook);
	NPC_Actor* Char1 = new NPC_Actor("char1.txt", &worldstate, &planner, camp, historyBook);
	NPC_Actor* Char2 = new NPC_Actor("char2.txt", &worldstate, &planner, camp, historyBook);
	DramaManager *Fate = new DramaManager(Char1, Char2, historyBook);

	//std::queue<Action> plans;
	Actor *actors[MAX_ACTORS];	//Array of the 4 actors in the scene.
	
	sf::Clock clock;
	sf::Time time;
	bool executePlans = true;

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

