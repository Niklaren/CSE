#pragma once

// Action includes
// drama manager
#include "BeginLRR.h"
#include "End.h"
// travel actions
#include "Travel.h"
#include "Leave.h"
#include "Arrive.h"
// player actions
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
// wolf actions
#include "WolfGreetRed.h"
#include "GiveDirections.h"
#include "GiveWrongDirections.h"
#include "WolfKnowsGrandmaReaction.h"
#include "QueryIdentity.h"
#include "QueryPurpose.h"
#include "QueryBasket.h"
#include "WolfEat.h"
#include "WolfEatLunch.h"
#include "Intimidate.h"
#include "SuggestFlowers.h"
// grandma actions
#include "OpenDoor.h"
#include "Forgive.h"
#include "Reprimand.h"
// lumberjack actions
#include "GrabLog.h"
#include "LogOnStump.h"
#include "ChopLog.h"
#include "AgreeEscort.h"
#include "RefuseEscort.h"
#include "KillWolf.h"
// misc other actions
#include "Greet.h"
#include "Hug.h"
#include "Kiss.h"
#include "Apologize.h"
#include "Thank.h"
//#include "OK.h"
#include "Insult.h"
#include "Punch.h"
#include "Intervene.h"

// vector for data structures
#include <vector>

#include "HistoryBook.h"
#include "Stage.h"

using namespace std;

// Actor base class
// all actors in the application must inherit this
// has some virtual classesthat may require specific implementations
class Actor
{
protected:
	// actors have a name and ID to kepp track of them.
	string name;
	int ID;
	
	// actor has location
	Stage* location;
	// actors write their actions to the history book and can perform lookup of previous actions
	HistoryBook* historyBook;

	// vector of available actions & current plans
	vector<Action*> availableActions;
	vector<Action*> plans;

public:
	Actor(string name, Stage* l, HistoryBook& hb);
	Actor(HistoryBook& hb);
	~Actor();

	// AddAction/RemoveAction classes Player_actor needs different implementation than the default
	virtual void AddAction(string ActionName);
	virtual void AddAction(string ActionName, Actor* target);
	virtual void AddAction(string ActionName, Stage* location_);
	virtual void AddLocation(string locName){} // unrequired in this scenario as travel is handled by specific actions

	virtual void RemoveAction(string ActionName);
	virtual void RemoveAction(string ActionName, Actor* target);
	virtual void RemoveAllActions();

	vector<Action*> Get_AvailableActions() { return availableActions; }
	int Get_NumActions() { return availableActions.size(); }
	virtual Action* Get_AvailableAction(int i) { return availableActions[i]; }

	// Reaction and planning
	virtual bool React() = 0;

	// plan by putting an action to the plans vector
	// do these need to be virtual? makes it look cleaner. but main difference is just the actions they perform. not how they're processed.
	virtual void Plan(string action){}
	virtual void Plan(string action, Actor* object){}
	virtual void Plan(string action, Stage* l, int moments = 1){}
	//virtual void Plan(string action, int m = 1, Actor* o = nullptr, Stage* s = nullptr){}
	
	void ClearAllPlans();
	void DiscardPlan(int index) { plans.erase(plans.begin() + index); }
	
	int GetNumPlans() { return plans.size(); }
	Action* GetPlan(int index) { return plans[index]; }
	Action* GetCurrentPlan() { return plans[0]; }
	Action* GetNextPlan() { return plans[1]; }
	
	string GetName() { return name; }
	int GetID() { return ID; }
	void SetID(int id) { ID = id; }

	Stage* GetLocation(){ return location; }
	void MoveLocation(Stage* l){ location = l; }
	
	void Wait(int time = 1);
	void TimeForward();

	HistoryBook* GetHistory(){ return historyBook; }
};

