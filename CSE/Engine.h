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
#include <vector>
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
	
	Input* input;
	HistoryBook historyBook;
	Planner planner;
	WorldState worldstate;
	Menu menu;

	Stage* offStage = new Stage("Assets/l_stage.png", "offStage");
	//Stage* camp = new Stage("camp.bmp", "camp");
	Stage* path = new Stage("Assets/l_path.png", "path");
	Stage* forest = new Stage("Assets/l_forest.png", "forest");
	Stage* cabin = new Stage("Assets/l_cabin.png", "cabin");
	Stage* lodge = new Stage("Assets/l_lodge.png", "lodge");
	

	Player_Actor *Protagonist = new Player_Actor("You", path, historyBook);
	NPC_Actor* Wolf = new NPC_Actor("Assets/c_wolf.txt", &worldstate, &planner, forest, historyBook);
	NPC_Actor* Lumberjack = new NPC_Actor("Assets/c_lumberjack.txt", &worldstate, &planner, cabin, historyBook);
	NPC_Actor* Grandma = new NPC_Actor("Assets/c_grandma.txt", &worldstate, &planner, lodge, historyBook);
	DramaManager *Fate = new DramaManager(offStage, &worldstate, historyBook);
	vector<Actor*> actors;
	vector<NPC_Actor*> NPCs;
	
	sf::Clock clock;
	sf::Time time;
	bool executePlans = true;
	bool playerAct = true;

	sf::Sprite stageSprite;
	sf::Texture stageTexture;

public:
	Engine(Input*);
	~Engine();

	void Init();

	bool Operate();

	void GetUserInput();

	void HandleInput(InputType);
	void HandleInput(InputType, float x, float y);
	//void HandleInput(InputType,LPARAM);
	//void HandleInput(InputType,WPARAM);

	void Redraw(sf::RenderWindow&);
	//bool BlitBitmap(HBITMAP hBitmap, HDC hWinDC, int x, int y);
};

