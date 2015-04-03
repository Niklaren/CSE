#include "stdafx.h"
#include "DramaManager.h"
#include "NPC_Actor.h"

DramaManager::DramaManager(NPC_Actor * c1, NPC_Actor * c2, HistoryBook& hb)
	: Actor("fate",hb)
{
	char1 = c1;
	char2 = c2;
}


DramaManager::~DramaManager()
{
}

void DramaManager::React()
{
	//Action reactingEvent = historyBook->GetLastEvent(); //??

	//reactingEvent.CalculateInclination(this);
}

void DramaManager::Plan(string action)
{
	if (action == "Begin")
		plans.push_back(new BeginStory(this, char1, char2, 1));
	else if (action == "Prepare")
		plans.push_back(new Prepare(char1, 1));
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
		BeginStory* beginStory_ = new BeginStory(this, object_, extra_, 1);
		plans.push_back(beginStory_);
	}
	else if (action == "."){

	}
	else{
		// error
	}
}

void DramaManager::CheckForPlanning()
{
	if (historyBook->TimeSinceStart() == 0)
		Plan("Begin");
	if (historyBook->TimeSinceStart() == 5)
		Plan("Prepare");

}