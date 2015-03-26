#pragma once

#include "BeginStory.h"
#include "OK.h"
#include "Punch.h"
#include "Hug.h"
#include "Insult.h"
#include "Apologize.h"
#include "Intervene.h"
#include "Greet.h"

//#include <string>
#include <list>
#include <vector>

#include "HistoryBook.h"

using namespace std;

class Actor
{
protected:
	vector<Action*> plans;
	string name;

	HistoryBook* historyBook;

public:
	Actor(string name, HistoryBook& hb);
	Actor(HistoryBook& hb);
	~Actor();

	virtual void React() {}
	virtual void Plan(string action);
	virtual void Plan(string action, Actor* object) {}
	virtual void Plan(string action, Actor*, Actor*) {}

	virtual string GetName() { return "Base"; }
	int GetNumPlans() { return plans.size(); }
	Action* GetPlan(int index) { return plans[index]; }
	void DiscardPlan(int index) { plans.erase(plans.begin()+index); }
	
	void TimeForward();
};

