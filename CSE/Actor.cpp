#include "stdafx.h"
#include "Actor.h"


Actor::Actor(string name_, HistoryBook &hb)
	: name(name_)
{
	historyBook = &hb;
}

Actor::Actor(HistoryBook &hb)
{
	historyBook = &hb;
}

Actor::~Actor()
{
}

void Actor::AddAction(string action)
{
	if (action == "OK")
		availableActions.push_back(new OK(this, 0));
	else if (action == "Travel")
		availableActions.push_back(new Travel(this, 0));
	else if (action == "Eat")
		availableActions.push_back(new Eat(this, 0));
	else if (action == "CookGood")
		availableActions.push_back(new CookGood(this, 0));
	else if (action == "CookBad")
		availableActions.push_back(new CookBad(this, 0));
	//else if (action == "FetchWater")
	//	availableActions.push_back(new FetchWater(this, 0));
	else if (action == "FetchWood")
		availableActions.push_back(new FetchWood(this, 0));
	else if (action == "Unpack")
		availableActions.push_back(new Unpack(this, 0));
	else if (action == "BuildStove")
		availableActions.push_back(new BuildStove(this, 0));
}

void Actor::AddAction(string action, Stage* location_)
{
	if (action == "FetchWater")
		availableActions.push_back(new FetchWater(this, location, 0));

}

void Actor::AddAction(string action, Actor* object_ = NULL)
{
	if (!object_)
		return;

	else if (action == "Greet")
		availableActions.push_back(new Greet(this, object_, 0));
	else if (action == "Hug")
		availableActions.push_back(new Hug(this, object_, 0));
	else if (action == "Insult")
		availableActions.push_back(new Insult(this, object_, 0));
	else if (action == "Punch")
		availableActions.push_back(new Punch(this, object_, 0));
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

void Actor::Plan(string action)
{
	// http://stackoverflow.com/questions/493490/converting-a-string-to-a-class-name
	//Type elementType = Type.GetType("Customer");
	//Type listType = typeof(List<>).MakeGenericType(new Type[] { elementType });
	//object list = Activator.CreateInstance(listType);

	// alternate/simpler approach
	// probably be a switch instead but w/e
	if (action == "OK"){
		
	}
	else if (false){
		//else if action == bla ...
	}
	else{
	//error
	}
}

void Actor::TimeForward()
{
	for (int plan_iter(0); plan_iter < GetNumPlans(); plan_iter++){
		GetPlan(plan_iter)->MomentsPass();
	}
}