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

void Action::React()
{
	if (HasSubject())
		subject->React();
	if (HasObject())
		object->React();

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