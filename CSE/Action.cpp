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
	bool reaction = false;
	if (HasSubject()){
		subject->React();
		reaction = true;
	}
	if (HasObject()){
		object->React();
		reaction = true;
	}

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

bool Action::ReadyToExecute() { 
	if (momentsFromExecution == 0) 
		{ return true; } 
	return false; 
}

void Action::MomentsPass() {
	momentsFromExecution--;
	return;
}
double Action::Blend(double a, double b, double weight)
{
	double uWeight = 1 - ((1 - weight) / 2);
	double blend = a*(1-uWeight) + b*uWeight;

	return blend;
}