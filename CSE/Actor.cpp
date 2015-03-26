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