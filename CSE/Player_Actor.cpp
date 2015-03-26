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

void Player_Actor::Plan(string action, Actor* object)
{
	if (action == "OK"){
		OK* ok_ = new OK(this, 1);
		plans.push_back(ok_);
	}
	else if (action == "Punch"){
		Punch* punch_ = new Punch(this, object, 1);
		plans.push_back(punch_);
	}
	else if (action == "Hug"){
		Hug* hug_ = new Hug(this, object, 1);
		plans.push_back(hug_);
	}
	if (action == "Apologize"){
		Apologize* apologize_ = new Apologize(this, object, 1);
		plans.push_back(apologize_);
	}
	else if (action == "Insult"){
		Insult* insult_ = new Insult(this, object, 1);
		plans.push_back(insult_);
	}
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