#include "stdafx.h"
#include "Player_Actor.h"


Player_Actor::Player_Actor(string name, HistoryBook& hb)
	: Actor(name,hb)
{
}


Player_Actor::~Player_Actor()
{
}

void Player_Actor::React()
{

}

void Player_Actor::Plan(string action)
{
	if (action == "OK"){
		OK* ok_ = new OK(this, 1);
		plans.push_back(ok_);
	}
	else{
		//error
	}
}

void Player_Actor::Plan(string action, Actor* object_)
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
	else if (action == "FetchWater")
		plans.push_back(new FetchWater(this, 1));
	else if (action == "FetchWood")
		plans.push_back(new FetchWood(this, 1));
	else if (action == "Unpack")
		plans.push_back(new Unpack(this, 1));
	else if (action == "BuildStove")
		plans.push_back(new BuildStove(this, 1));
	else{
		//error
	}


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
	if (action == "Apologize")
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