#pragma once

#include "Actor.h"

class DramaManager : public Actor
{
private:
	//vector<NPC_Actor*> NPCs;
	Actor* red, *wolf, *lumberjack, *grandma;
	Stage* path, *forest, *cabin, *lodge;

public:
	DramaManager(Stage* s, HistoryBook& hb);
	~DramaManager();

	void SetCharacters(Actor* p, Actor* w, Actor* l, Actor* g);
	void SetLocations(Stage* path, Stage* forest, Stage* cabin, Stage* lodge);

	void InitLRR();

	virtual bool React();
	virtual void Plan(string);
	virtual void Plan(string, Actor*);
	virtual void Plan(string, Actor*, Actor*);
	void CheckForPlanning();


	string GetName() { return "Fate"; }
};

