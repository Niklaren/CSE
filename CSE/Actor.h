#pragma once

#include "BeginStory.h"
#include "BeginLRR.h"
#include "Prepare.h"

#include "OK.h"
#include "Travel.h"
#include "Observe.h"
#include "WalkPath.h"

#include "WolfGreetRed.h"
#include "QueryIdentity.h"
#include "QueryPurpose.h"
#include "QueryBasket.h"

#include "GrabLog.h"
#include "LogOnStump.h"
#include "ChopLog.h"

#include "Punch.h"
#include "Hug.h"
#include "Insult.h"
#include "Apologize.h"
#include "Intervene.h"
#include "Greet.h"
#include "Eat.h"
//#include "CookGood.h"
//#include "CookBad.h"
//#include "BuildStove.h"
//#include "FetchWater.h"
//#include "FetchWood.h"
//#include "Unpack.h"


//#include <string>
#include <list>
#include <vector>

#include "HistoryBook.h"
#include "Stage.h"

using namespace std;

class Actor
{
protected:
	string name;

	Stage* location;

	HistoryBook* historyBook;

	vector<Action*> availableActions;
	vector<Action*> plans;

public:
	Actor(string name, Stage* l, HistoryBook& hb);
	Actor(HistoryBook& hb);
	~Actor();

	virtual void AddAction(string ActionName);
	virtual void AddAction(string ActionName, Actor* target);
	virtual void AddAction(string ActionName, Stage* location_);

	virtual void RemoveAction(string ActionName);

	vector<Action*> Get_AvailableActions() { return availableActions; }
	int Get_NumActions() { return availableActions.size(); }
	Action* Get_AvailableAction(int i) { return availableActions[i]; }

	virtual bool React() = 0;
	virtual void Plan(string action);
	virtual void Plan(string action, Actor* object){}
	virtual void Plan(string action, Stage* l){}
	virtual void Plan(string action, Actor*, Actor*){}


	virtual string GetName() { return "Base"; }
	int GetNumPlans() { return plans.size(); }
	Action* GetPlan(int index) { return plans[index]; }
	Action* GetCurrentPlan() { return plans[0]; }
	Action* GetNextPlan() { return plans[1]; }
	void DiscardPlan(int index) { plans.erase(plans.begin()+index); }

	Stage* GetLocation(){ return location; }
	void MoveLocation(Stage* l){ location = l; }
	
	void TimeForward();

	HistoryBook* GetHistory(){ return historyBook; }
};

