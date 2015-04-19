#pragma once

#include "NPC_Actor.h"
#include "Player_Actor.h"

class DramaManager : public Actor
{
private:
	//vector<NPC_Actor*> NPCs;
	Player_Actor* red;
	NPC_Actor*wolf, *lumberjack, *grandma;
	Stage* path, *forest, *cabin, *lodge, *offstage;
	WorldState* ws;
public:
	DramaManager(Stage* s, WorldState* ws_, HistoryBook& hb);
	~DramaManager();

	void SetCharacters(Player_Actor* p, NPC_Actor* w, NPC_Actor* l, NPC_Actor* g);
	void SetLocations(Stage* path, Stage* forest, Stage* cabin, Stage* lodge, Stage* offstage);

	void InitLRR();

	virtual bool React();
	virtual void Plan(string);
	virtual void Plan(string, Actor*);
	virtual void Plan(string, Actor*, Actor*);
	void CheckForPlanning();

	bool ended = false;
};

