#pragma once

#include "Actor.h"

class DramaManager : public Actor
{
private:
	NPC_Actor* char1;
	NPC_Actor* char2;

public:
	DramaManager(NPC_Actor* char1, NPC_Actor*char2, HistoryBook& hb);
	~DramaManager();

	virtual void React();
	virtual void Plan(string);
	virtual void Plan(string, Actor*);
	virtual void Plan(string, Actor*, Actor*);
	void CheckForPlanning();


	string GetName() { return "Fate"; }
};

