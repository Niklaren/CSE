#pragma once

#include "BeginStory.h"
#include "BeginLRR.h"
#include "Prepare.h"
#include "End.h"

#include "OK.h"
#include "Travel.h"
#include "Leave.h"
#include "Arrive.h"

#include "Observe.h"
#include "GoHome.h"
#include "WalkPath.h"
#include "RequestEntry.h"
#include "GiveFood.h"
#include "AskDirections.h"
#include "WalkAway.h"
#include "Answer.h"
#include "Ignore.h"
#include "Flee.h"
#include "PickFlowers.h"
#include "GiveFlowers.h"
#include "RequestEscort.h"

#include "WolfGreetRed.h"
#include "GiveDirections.h"
#include "GiveWrongDirections.h"
#include "QueryIdentity.h"
#include "QueryPurpose.h"
#include "QueryBasket.h"
#include "WolfEat.h"
#include "WolfEatLunch.h"
#include "Intimidate.h"
#include "SuggestFlowers.h"

#include "OpenDoor.h"

#include "GrabLog.h"
#include "LogOnStump.h"
#include "ChopLog.h"
#include "AgreeEscort.h"
#include "RefuseEscort.h"
#include "KillWolf.h"

#include "Greet.h"
#include "Hug.h"
#include "Kiss.h"
#include "Apologize.h"
#include "Thank.h"
#include "Forgive.h"
#include "Reprimand.h"

#include "Insult.h"
#include "Punch.h"
#include "Intervene.h"

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
	int ID;

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
	//virtual void AddAction(string ActionName, Actor* target, Stage* location_);
	virtual void AddLocation(string locName){}

	virtual void RemoveAction(string ActionName);
	virtual void RemoveAction(string ActionName, Actor* target);

	vector<Action*> Get_AvailableActions() { return availableActions; }
	int Get_NumActions() { return availableActions.size(); }
	Action* Get_AvailableAction(int i) { return availableActions[i]; }

	virtual bool React() = 0;
	virtual void Plan(string action);
	virtual void Plan(string action, Actor* object){}
	virtual void Plan(string action, Stage* l, int moments = 1){}
	//virtual void Plan(string action, int m = 1, Actor* o = nullptr, Stage* s = nullptr){}

	string GetName() { return name; }
	int GetID() { return ID; }
	void SetID(int id) { ID = id; }

	int GetNumPlans() { return plans.size(); }
	Action* GetPlan(int index) { return plans[index]; }
	Action* GetCurrentPlan() { return plans[0]; }
	Action* GetNextPlan() { return plans[1]; }
	void DiscardPlan(int index) { plans.erase(plans.begin()+index); }

	Stage* GetLocation(){ return location; }
	void MoveLocation(Stage* l){ location = l; }
	
	void Wait(int time = 1);
	void TimeForward();

	HistoryBook* GetHistory(){ return historyBook; }
};

