#include "stdafx.h"
#include "Player_Actor.h"
#include "NPC_Actor.h"

Player_Actor::Player_Actor(string name, Stage* s, HistoryBook& hb)
	: Actor(name, s, hb)
{
	s_availableLocations.reserve(5);
	s_availableCharacters.reserve(4);
	s_availableCharacters.assign(4, "Unavailable");
}


Player_Actor::~Player_Actor()
{
}

void Player_Actor::AddAction(string action)
{
	if (action == "OK")
		s_availableActions.push_back("OK");
	else if (action == "Travel")
		s_availableActions.push_back("Travel");
	else if (action == "Stray Off Path")
		s_availableActions.push_back("Stray Off Path");
	else if (action == "Walk Path")
		s_availableActions.push_back("Walk Path");
	else if (action == "Request Entry")
		s_availableActions.push_back("Request Entry");
	else if (action == "Go Home")
		s_availableActions.push_back("Go Home");
	else if (action == "Observe")
		s_availableActions.push_back("Observe");
	else if (action == "Eat")
		s_availableActions.push_back("Eat");
	else if (action == "Answer")
		s_availableActions.push_back("Answer");
	else if (action == "Give Food")
		s_availableActions.push_back("Give Food");
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
	for (unsigned i = s_availableActions.size(); i-- > 0;)
	{
		if (s_availableActions[i] == action)
			s_availableActions.erase(s_availableActions.begin() + i);
	}
}

void Player_Actor::RemoveAllActions()
{
	s_availableActions.clear();
	s_availableActions.push_back("OK");
}

void Player_Actor::SetAvailableCharacters(vector<NPC_Actor*> NPCs)
{
	for (unsigned i(0); i < NPCs.size(); i++){
		if (NPCs[i]->GetLocation() == location)
			s_availableCharacters.at(i) = NPCs[i]->GetName();
		else
			s_availableCharacters.at(i) = "Unavailable";
	}
}

bool Player_Actor::React()
{
	return false;
}

void Player_Actor::Plan(string action)
{
	// actions that do not have an object;
	if (action == "OK")
		plans.push_back(new OK(this, 1));
	else if (action == "Observe")
		plans.push_back(new Observe(this, 1));
	else if (action == "Go Home")
		plans.push_back(new GoHome(this, 1));
	else if (action == "Walk Path")
		plans.push_back(new WalkPath(this, 1));
	//else if (action == "Eat")
	//	plans.push_back(new Eat(this, 1));
	//else if (action == "CookGood")
	//	plans.push_back(new CookGood(this, 1));
	//else if (action == "CookBad")
	//	plans.push_back(new CookBad(this, 1));
	//else if (action == "Unpack")
	//	plans.push_back(new Unpack(this, 1));
	//else if (action == "BuildStove")
	//	plans.push_back(new BuildStove(this, 1));
	else{
		//error
	}

	//location actions
	//if (action == "FetchWater")
	//	plans.push_back(new FetchWater(this, location, 1));
	//else if (action == "FetchWood")
	//	plans.push_back(new FetchWood(this, 1));
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
	else if (action == "Request Entry")
		plans.push_back(new RequestEntry(this, object_, 1));
	else if (action == "Apologize")
		plans.push_back(new Apologize(this, object_, 1));
	else if (action == "Insult")
		plans.push_back(new Insult(this, object_, 1));
	else if (action == "Answer")
		plans.push_back(new Answer(this, object_, 1));
	else if (action == "Give Food")
		plans.push_back(new GiveFood(this, object_, 1));
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

void Player_Actor::Plan(string action, Stage* l)
{
	if (action == "Travel")
		plans.push_back(new Travel(this, l, 1));
	else if (action == "Stray Off Path")
		plans.push_back(new Travel(this, l, 1, "Stray Off Path"));
}