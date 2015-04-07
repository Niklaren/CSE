#pragma once

#include "Actor.h"


class Player_Actor : public Actor
{
public: // ??? for now
	vector<string> s_availableActions;

public:
	Player_Actor(string name, Stage* startlocation, HistoryBook& hb);
	~Player_Actor();

	virtual void AddAction(string ActionName);
	virtual void RemoveAction(string ActionName);
	vector<string> Get_AvailableActions() { return s_availableActions; }

	virtual void React();
	virtual void Plan(string);
	virtual void Plan(string, Actor*);
	virtual void Plan(string, NPC_Actor*, NPC_Actor*);

	virtual string GetName() { return name; }
	//optionspicked()
};

