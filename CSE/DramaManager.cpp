#include "stdafx.h"
#include "DramaManager.h"
#include "NPC_Actor.h"
#include "Player_Actor.h"

DramaManager::DramaManager(Stage* s, HistoryBook& hb)
	: Actor("fate", s, hb)
{

}


DramaManager::~DramaManager()
{
}

void DramaManager::SetCharacters(Actor* p, Actor* w, Actor* l, Actor* g)
{
	red = p;
	wolf = w;
	lumberjack = l;
	grandma = g;
}

void DramaManager::SetLocations(Stage* p, Stage* f, Stage* c, Stage* l)
{
	path = p;
	forest = f;
	cabin = c;
	lodge = l;
}

void DramaManager::InitLRR()
{
	red->AddAction("Greet");
	red->AddAction("Travel");
	static_cast<Player_Actor*>(red)->AddLocation("cabin");

	wolf->AddAction("OK");
	wolf->AddAction("Travel");
	wolf->AddAction("Eat");

	wolf->AddAction("WolfGreetRed", red);
	wolf->AddAction("QueryIdentity", red);
	wolf->AddAction("QueryPurpose", red);
	wolf->AddAction("QueryBasket", red);

	lumberjack->AddAction("OK");

	lumberjack->AddAction("ChopLog", cabin);
	lumberjack->AddAction("LogOnstump", cabin);
	lumberjack->AddAction("Grablog", cabin);
	lumberjack->AddAction("Travel");
	lumberjack->AddAction("Greet", red);
	
}

bool DramaManager::React()
{
	//Action reactingEvent = historyBook->GetLastEvent(); //??

	//reactingEvent.CalculateInclination(this);
	return false;
}

void DramaManager::Plan(string action)
{
	if (action == "Begin")
		//plans.push_back(new BeginStory(this, wolf, 0));
		plans.push_back(new BeginLRR(this, red, wolf, lumberjack, grandma, 0));
	else if (action == "Prepare")
		;//plans.push_back(new Prepare(char1, 1));
	else{
		// error
	}
}

void DramaManager::Plan(string action, Actor* object)
{
	if (action == "."){

	}
	else{
		// error
	}
}

void DramaManager::Plan(string action, Actor* object_, Actor* extra_)
{
	if (action == "Begin")
	{
		//initialise with a story begin plan
		plans.push_back(new BeginStory(this, object_, 0));
	}
	else if (action == "."){

	}
	else{
		// error
	}
}

void DramaManager::CheckForPlanning()
{
	if (historyBook->TimeSinceStart() == 1)
		Plan("Begin");
	if (historyBook->TimeSinceStart() == 6)
		Plan("Prepare");

	//if ()

	//if ((historyBook->TimeElapsedSince("QueryIdentity")>2) && (historyBook->HaventDoneEventBefore(red,"ReplyIdentity"))
	//if ((historyBook->TimeElapsedSince("QueryPurpose")>2) && (historyBook->HaventDoneEventBefore(red,"ReplyPurpose"))
	//if ((historyBook->TimeElapsedSince("QueryBasket")>2) && (historyBook->HaventDoneEventBefore(red,"ReplyBasket"))

}