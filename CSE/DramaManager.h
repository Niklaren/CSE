#pragma once
#include "NPC_Actor.h"
#include "Player_Actor.h"

// Since there could be unique DramaManagers for individual stories or genres a DramaManger superclass was made
// However since there are a lot of things specific to this story (and we only have one story) it doesnt get much use.
// In theory all DramaManager Subclasses would have to implement this interface
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
	//virtual void Plan(string, Actor*, Actor*) = 0; // can be used to make an actors to perform  an action with/to another etc.
	virtual void CheckForPlanning() = 0;

	bool ended = false;
};
