#pragma once

#include "NPC_Actor.h"
#include "Player_Actor.h"
#include "DramaManager.h"

class LRR_DramaManager : public DramaManager
{
private:
	//vector<NPC_Actor*> NPCs;
	Player_Actor* red;
	NPC_Actor*wolf, *lumberjack, *grandma;
	Stage* path, *forest, *cabin, *lodge, *offstage;

	BeginLRR* begin;
public:
	LRR_DramaManager(Stage* s, WorldState* ws_, HistoryBook& hb);
	~LRR_DramaManager();

	void SetCharacters(Player_Actor* p, NPC_Actor* w, NPC_Actor* l, NPC_Actor* g);
	void SetLocations(Stage* path, Stage* forest, Stage* cabin, Stage* lodge, Stage* offstage);

	void Init();

	virtual bool React();
	virtual void Plan(string);
	virtual void Plan(string, Actor*);
	virtual void Plan(string, Actor*, Actor*);
	virtual void CheckForPlanning();

};

