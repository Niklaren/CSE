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
	s_availableActions.push_back(action);

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
	if (action == "Observe")
		plans.push_back(new Observe(this, 1));
	else if (action == "Go Home")
		plans.push_back(new GoHome(this, 1));
	else if (action == "Walk Path")
		plans.push_back(new WalkPath(this, 1));
	else if (action == "Walk Away")
		plans.push_back(new WalkAway(this, 1));
	else if (action == "Pick Flowers")
		plans.push_back(new PickFlowers(this, 1));
	else{
		//error
	}

	//location actions
	//if (action == "A")
	//	plans.push_back(new A(this, location, 1));

}

void Player_Actor::Plan(string action, Actor* object_)
{


	// actions that have an object;
	if (!object_)
	{
		std::cout << "object null" << std::endl;
		return;
	}

	if (action == "Hug")
		plans.push_back(new Hug(this, object_, 1));
	else if (action == "Greet")
		plans.push_back(new Greet(this, object_, 1));
	else if (action == "Knock Door")
		plans.push_back(new RequestEntry(this, object_, 1));
	else if (action == "Apologize")
		plans.push_back(new Apologize(this, object_, 1));
	else if (action == "Insult")
		plans.push_back(new Insult(this, object_, 1));
	else if (action == "Answer")
		plans.push_back(new Answer(this, object_, 1));
	else if (action == "Ignore")
		plans.push_back(new Ignore(this, object_, 1));
	else if (action == "Give Food")
		plans.push_back(new GiveFood(this, object_, 1));
	else if (action == "Give Flowers")
		plans.push_back(new GiveFlowers(this, object_, 1));
	else if (action == "Ask Directions")
		plans.push_back(new AskDirections(this, object_, 1));
	else if (action == "Thank")
		plans.push_back(new Thank(this, object_, 1));
	else if (action == "Request Escort")
		plans.push_back(new RequestEscort(this, object_, 1));
	else{
		//error
	}
}

//void Player_Actor::Plan(string action, NPC_Actor* a1, NPC_Actor* a2)
//{
//	if (action == "Intervene"){
//		Intervene* intervene_ = new Intervene(this, a1, a2, 1);
//		plans.push_back(intervene_);
//	}
//}

void Player_Actor::Plan(string action, Stage* l, int moments)
{
	if (action == "Travel")
		plans.push_back(new Travel(this, l, moments));
	//if (action == "Leave")
	//	plans.push_back(new Leave(this, moments));
	if (action == "Arrive")
		plans.push_back(new Arrive(this, l, moments));
	else if (action == "Stray Off Path")
		plans.push_back(new Travel(this, l, moments, "Stray Off Path"));
	else if (action == "Flee"){
		plans.push_back(new Flee(this, l, 1));
	}
}