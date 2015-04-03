#pragma once

#include "Actor.h"
#include "Menu.h"

class Player_Actor : public Actor
{
public: // ??? for now
	//options ?
	Menu menu;

public:
	Player_Actor(string name, HistoryBook& hb);
	~Player_Actor();

	virtual void React();
	virtual void Plan(string);
	virtual void Plan(string, Actor*);
	virtual void Plan(string, NPC_Actor*, NPC_Actor*);

	virtual string GetName() { return name; }
	//optionspicked()
	//void Plan(wstring);
};

