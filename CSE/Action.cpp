#include "stdafx.h"
#include "Action.h"
#include "Actor.h"

Action::Action(Actor* subject_, int momentsFromExecution_)
{
	subject = subject_;
	momentsFromExecution = momentsFromExecution_;
}

Action::Action()
{
}

Action::~Action()
{
}

bool Action::React() // by default only subjects reacts.
{
	bool reaction = subject->React();

	return reaction;
}

// default response is to set the location the action occured (if there was previoulsy none)
void Action::ExecuteConsequences(WorldState* ws)
{
	if (!locationOccured)
	{
		locationOccured = subject->GetLocation();
	}
}

// by default no emotional reaction
void Action::EmotionalReaction(NPC_Actor* affectedActor)
{
}

// default = subject verbs. (eg Nick types)
std::string Action::GetSentence(){
	std::string eventText = "";
	std::string ssubject = subject->GetName();

	eventText = ssubject + " " + verb + "s.";

	return eventText;
}

// check if action is ready to execute
bool Action::ReadyToExecute() 
{ 
	if (momentsFromExecution != 0)
		return false;

	if (!GetUsable())
		return false;

	if (locationOccured != nullptr){	// if its not at its required location we should delay this action & travel there.
		if ((subject->GetLocation() != locationOccured) && (subject->GetName() != "fate")){ //can improve with planning travel upgrade.
			subject->Wait(1);
			subject->Plan("Travel", locationOccured, 0);
			return false;
		}
	}
		
	return true; 
	
}

void Action::MomentsPass() {
	momentsFromExecution--;
	return;
}

// - weights favor a, + weight favours b
double Action::Blend(double a, double b, double weight)
{
	double uWeight = 1 - ((1 - weight) / 2);
	double blend = a*(1-uWeight) + b*uWeight;

	return blend;
}