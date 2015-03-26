#pragma once

#include "Actor.h"

class DramaManager : public Actor
{
public:
	DramaManager(string name, HistoryBook& hb);
	~DramaManager();

	virtual void React();
	virtual void Plan(string);
	virtual void Plan(string, Actor*);
	virtual void Plan(string, Actor*, Actor*);


	string GetName() { return "Fate"; }
};

