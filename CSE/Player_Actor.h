#pragma once

#include "Actor.h"
#include "Menu.h"

struct MenuOption
{
	string name;
	enum {Locked, Unlocked, Available} availabilty;

	MenuOption()
	{

	}
};

class Player_Actor : public Actor
{
public: // ??? for now
	//vector<MenuOption> o_availableActions;
	//vector<MenuOption> o_availableLocations;
	//vector<MenuOption> o_availableCharacters;
	vector<string> s_availableActions;
	vector<string> s_availableLocations;
	vector<string> s_availableCharacters;

public:
	Player_Actor(string name, Stage* startlocation, HistoryBook& hb);
	~Player_Actor();

	virtual void AddAction(string ActionName);
	virtual void RemoveAction(string ActionName);
	void RemoveAllActions();
	vector<string> Get_AvailableActions() { return s_availableActions; }
	void AddLocation(string LName) { s_availableLocations.push_back(LName); }
	vector<string> Get_AvailableLocations() { return s_availableLocations; }
	void SetAvailableCharacters(vector<NPC_Actor*> NPCs);
	vector<string> Get_AvailableCharacters() { return s_availableCharacters; }

	virtual bool React();
	virtual void Plan(string);
	virtual void Plan(string, Actor*);
	virtual void Plan(string, NPC_Actor*, NPC_Actor*);
	virtual void Plan(string action, Stage* l, int moments = 1);

	//optionspicked()

	Menu menu;
};

