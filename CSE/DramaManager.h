#pragma once
#include "NPC_Actor.h"
#include "Player_Actor.h"

class DramaManager :
	public Actor
{
protected:	
	WorldState* ws;

public:
	DramaManager(Stage* s, WorldState* ws_, HistoryBook& hb);
	~DramaManager();

	//virtual void SetCharacters();
	//virtual void SetLocations();

	virtual void Init() = 0;

	virtual bool React() = 0;
	virtual void Plan(string) = 0;
	virtual void Plan(string, Actor*) = 0;
	virtual void Plan(string, Actor*, Actor*) = 0;
	virtual void CheckForPlanning() = 0;

	bool ended = false;
};
