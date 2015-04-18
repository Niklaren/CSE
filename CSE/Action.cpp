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

bool Action::React()
{
	bool reaction = subject->React();

	return reaction;
}

void Action::ExecuteConsequences(WorldState* ws)
{
	if (!locationOccured)
	{
		locationOccured = subject->GetLocation();
	}
}

std::string Action::GetSentence(){
	std::string eventText = "";
	std::string ssubject = subject->GetName();

	eventText = ssubject + " " + verb + "s.";

	return eventText;
}

bool Action::ReadyToExecute() 
{ 
	if (momentsFromExecution != 0)
		return false;

	if (!GetUsable())
		return false;

	if (locationOccured != nullptr){
		if ((subject->GetLocation() != locationOccured) && (subject->GetName() != "fate")){
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