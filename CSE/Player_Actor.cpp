#include "stdafx.h"
#include "Player_Actor.h"


Player_Actor::Player_Actor(string name, Stage* s, HistoryBook& hb)
	: Actor(name,hb)
{
	location = s;
}


Player_Actor::~Player_Actor()
{
}

void Player_Actor::AddAction(string action)
{
	if (action == "OK")
		s_availableActions.push_back("OK");
	else if (action == "Eat")
		s_availableActions.push_back("Eat");
	else if (action == "Cook")
		s_availableActions.push_back("Cook");
	else if (action == "FetchWater")
		s_availableActions.push_back("FetchWater");
	else if (action == "FetchWood")
		s_availableActions.push_back("FetchWood");
	else if (action == "Unpack")
		s_availableActions.push_back("Unpack");
	else if (action == "BuildStove")
		s_availableActions.push_back("BuildStove");
	else if (action == "Greet")
		s_availableActions.push_back("Greet");
	else if (action == "Hug")
		s_availableActions.push_back("Hug");
	else if (action == "Insult")
		s_availableActions.push_back("Insult");
	else if (action == "Punch")
		s_availableActions.push_back("Punch");
}

void Player_Actor::RemoveAction(string action)
{
	for (unsigned i = availableActions.size(); i-- > 0;)
	{
		if (s_availableActions[i] == action)
			s_availableActions.erase(s_availableActions.begin() + i);
	}
}

void Player_Actor::React()
{

}

void Player_Actor::Plan(string action)
{
	// actions that do not have an object;
	if (action == "OK")
		plans.push_back(new OK(this, 1));
	else if (action == "Eat")
		plans.push_back(new Eat(this, 1));
	else if (action == "CookGood")
		plans.push_back(new CookGood(this, 1));
	else if (action == "CookBad")
		plans.push_back(new CookBad(this, 1));
	else if (action == "Unpack")
		plans.push_back(new Unpack(this, 1));
	else if (action == "BuildStove")
		plans.push_back(new BuildStove(this, 1));
	else{
		//error
	}

	//location actions
	if (action == "FetchWater")
		plans.push_back(new FetchWater(this, location, 1));
	else if (action == "FetchWood")
		plans.push_back(new FetchWood(this, 1));
}

void Player_Actor::Plan(string action, Actor* object_)
{


	// actions that have an object;
	if (!object_)
	{
		std::cout << "object null" << std::endl;
		return;
	}

	if (action == "Joke")
		plans.push_back(new Punch(this, object_, 1));
	else if (action == "Hug")
		plans.push_back(new Hug(this, object_, 1));
	else if (action == "Greet")
		plans.push_back(new Greet(this, object_, 1));
	else if (action == "Apologize")
		plans.push_back(new Apologize(this, object_, 1));
	else if (action == "Insult")
		plans.push_back(new Insult(this, object_, 1));
	else{
		//error
	}
}

void Player_Actor::Plan(string action, NPC_Actor* a1, NPC_Actor* a2)
{
	if (action == "Intervene"){
		Intervene* intervene_ = new Intervene(this, a1, a2, 1);
		plans.push_back(intervene_);
	}
}