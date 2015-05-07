#pragma once

#include <SFML/Graphics.hpp>

#include "Action.h"
#include "HistoryBook.h"
#include "WorldState.h"
#include "Actor.h"
#include "NPC_Actor.h"
#include "Player_Actor.h"
#include "DramaManager.h"
#include "LRR_DramaManager.h"
#include "Menu.h"
#include "Planner.h"

#include "Input.h"

#include <queue>
#include <vector>
#include <assert.h>

enum InputType {LDown, LUp, KeyDown, KeyUp, MouseMove};

#define MAX_ACTORS 4

// Engine class. encompasses the main game loop and everything required to operate this
class Engine
{
protected:
	int attempt;

	Input* input;
	HistoryBook historyBook;
	Planner planner;
	WorldState worldstate;

	// stages
	Stage* offStage = new Stage("Assets/l_stage.png", "offStage");
	Stage* path = new Stage("Assets/l_path.png", "path");
	Stage* forest = new Stage("Assets/l_forest.png", "forest");
	Stage* cabin = new Stage("Assets/l_cabin.png", "cabin");
	Stage* lodge = new Stage("Assets/l_lodge.png", "lodge");
	// characters
	Player_Actor *Protagonist = new Player_Actor("You", path, historyBook);
	NPC_Actor* Wolf = new NPC_Actor("Assets/c_wolf.txt", &worldstate, &planner, forest, historyBook);
	NPC_Actor* Lumberjack = new NPC_Actor("Assets/c_lumberjack.txt", &worldstate, &planner, cabin, historyBook);
	NPC_Actor* Grandma = new NPC_Actor("Assets/c_grandma.txt", &worldstate, &planner, lodge, historyBook);
	LRR_DramaManager *Fate = new LRR_DramaManager(offStage, &worldstate, historyBook);
	// list for actors + list for NPCs specifically
	vector<Actor*> actors;
	vector<NPC_Actor*> NPCs;
	
	// check for if the player is ready to act/is allowed act
	bool executePlans = true;
	bool playerAct = true;

	sf::Sprite stageSprite;
	sf::Texture stageTexture;

public:
	Engine(Input*, int);
	~Engine();

	void Init();

	bool Operate();

	void GetUserInput();

	void Redraw(sf::RenderWindow&);
};

