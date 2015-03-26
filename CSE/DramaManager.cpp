#include "stdafx.h"
#include "DramaManager.h"


DramaManager::DramaManager(string name, HistoryBook& hb)
	: Actor(name,hb)
{

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
	{

	}
	else if (action == "."){

	}
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
