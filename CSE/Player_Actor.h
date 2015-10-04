#pragma once

#include "Actor.h"
#include "Menu.h"

// player actor. the players avatar and character in the story.
// the player class has a menu object, which the player uses to select actions to perform
class Player_Actor : public Actor
{
public:
	// we can just use a string to represent available actions, locations & targets. less memory & easier to track.
	vector<string> s_availableActions;
	vector<string> s_availableLocations;
	vector<string> s_availableCharacters;
	// this does mean that adding and removing actions works a little differently.
public:
	Player_Actor(string name, Stage* startlocation, HistoryBook& hb);
	~Player_Actor();

	void AddAction(string ActionName);
	void RemoveAction(string ActionName);
	void RemoveAllActions();
	vector<string> Get_AvailableActions() { return s_availableActions; }
	
	void AddLocation(string LName) { s_availableLocations.push_back(LName); }	// locations not needed here since movement is
	vector<string> Get_AvailableLocations() { return s_availableLocations; }	// done through untargted actions such as 'flee'
	void SetAvailableCharacters(vector<NPC_Actor*> NPCs);
	vector<string> Get_AvailableCharacters() { return s_availableCharacters; }

	bool React();
	void Plan(string);
	void Plan(string, Actor*);
	//void Plan(string, NPC_Actor*, NPC_Actor*);	// no actions in this story require this
	void Plan(string action, Stage* l, int moments = 1);

	Menu menu;
};

