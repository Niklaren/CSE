#include "stdafx.h"
#include "Actor.h"


Actor::Actor(string name_, Stage* s, HistoryBook &hb)
	: name(name_)
{
	historyBook = &hb;
	location = s;
}

Actor::Actor(HistoryBook &hb)
{
	historyBook = &hb;
}

Actor::~Actor()
{
}

// add targetless/locationless actions
void Actor::AddAction(string action)
{
	if (action == "Travel")
		availableActions.push_back(new Travel(this, 0));
	else if (action == "OpenDoor")
		availableActions.push_back(new OpenDoor(this, 0));
	else if (action == "WolfEatLunch")
		availableActions.push_back(new WolfEatLunch(this, 0));
	else if (action == "WolfKnowsGrandmaReaction")
		availableActions.push_back(new WolfKnowsGrandmaReaction(this, 0));

}
//add location dependant actions
void Actor::AddAction(string action, Stage* location_)
{
	if (action == "ChopLog")
		availableActions.push_back(new ChopLog(this, location, 0));
	else if (action == "LogOnstump")
		availableActions.push_back(new LogOnStump(this, location, 0));
	else if (action == "Grablog")
		availableActions.push_back(new GrabLog(this, location, 0));

}
// add trgeted actions
void Actor::AddAction(string action, Actor* object_ = NULL)
{
	if (!object_)
		return;

	else if (action == "WolfGreetRed")
		availableActions.push_back(new WolfGreetRed(this, object_, 0));
	else if (action == "GiveDirections")
		availableActions.push_back(new GiveDirections(this, object_, 0));
	else if (action == "GiveWrongDirections")
		availableActions.push_back(new GiveWrongDirections(this, object_, 0));
	else if (action == "QueryIdentity")
		availableActions.push_back(new QueryIdentity(this, object_, 0));
	else if (action == "QueryPurpose")
		availableActions.push_back(new QueryPurpose(this, object_, 0));
	else if (action == "QueryBasket")
		availableActions.push_back(new QueryBasket(this, object_, 0));
	else if (action == "WolfEat")
		availableActions.push_back(new WolfEat(this, object_, 0));
	else if (action == "RequestEntry")
		availableActions.push_back(new RequestEntry(this, object_, 0));
	else if (action == "Intimidate")
		availableActions.push_back(new Intimidate(this, object_, 0));
	else if (action == "SuggestFlowers")
		availableActions.push_back(new SuggestFlowers(this, object_, 0));
	else if (action == "Greet")
		availableActions.push_back(new Greet(this, object_, 0));
	else if (action == "Thank")
		availableActions.push_back(new Thank(this, object_, 0));
	else if (action == "Hug")
		availableActions.push_back(new Hug(this, object_, 0));
	else if (action == "Kiss")
		availableActions.push_back(new Kiss(this, object_, 0));
	else if (action == "Forgive")
		availableActions.push_back(new Forgive(this, object_, 0));
	else if (action == "Reprimand")
		availableActions.push_back(new Reprimand(this, object_, 0));
	else if (action == "RefuseEscort")
		availableActions.push_back(new RefuseEscort(this, object_, 0));
	else if (action == "AgreeEscort")
		availableActions.push_back(new AgreeEscort(this, object_, 0));
	else if (action == "KillWolf")
		availableActions.push_back(new KillWolf(this, object_, 0));
}

void Actor::RemoveAction(string action)
{
	//std::vector<Action*>::reverse_iterator rit;
	//for (rit = availableActions.rbegin(); rit != availableActions.rend(); ++rit)
	for (unsigned i = availableActions.size(); i-- > 0;)
	{
		if (availableActions[i]->GetVerb() == action)
			availableActions.erase(availableActions.begin() + i);
	}
}

void Actor::RemoveAction(string action, Actor* object_)
{
	for (unsigned i = availableActions.size(); i-- > 0;)
	{
		if ((availableActions[i]->GetVerb() == action) && (availableActions[i]->Get_Object() == object_))
			availableActions.erase(availableActions.begin() + i);
	}
}

void Actor::RemoveAllActions()
{
	for (unsigned i = availableActions.size(); i-- > 0;)
	{
		availableActions.erase(availableActions.begin() + i);
	}
}

// hold off on executing an action for the delay period
void Actor::Wait(int delay)
{
	for (int plan_iter(0); plan_iter < GetNumPlans(); plan_iter++){
		GetPlan(plan_iter)->AddExecutionTime(delay);
	}
}

// a moment has passed, lower all the execution times of actions by 1
void Actor::TimeForward()
{
	for (int plan_iter(0); plan_iter < GetNumPlans(); plan_iter++){
		GetPlan(plan_iter)->MomentsPass();
	}
}