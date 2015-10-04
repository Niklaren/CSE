#include "stdafx.h"
//#include "Arrive.h"
#include "Actor.h"
#include "NPC_Actor.h"


Arrive::Arrive(Actor* subject_, int moments_)
	: Action(subject_, moments_)
{
	Init();
}

Arrive::Arrive(Actor* subject_, Stage* s, int moments_)
	: Action(subject_, moments_)
{
	locationOccured = s;
	Init();
}

Arrive::Arrive()
{
	Init();

}

Arrive::~Arrive()
{

}

void Arrive::Init()
{
	verb = "Arrive";

}

std::string Arrive::GetSentence()
{
	if (subject->GetName() == "You")
		return"You arrive at " + locationOccured->GetName();
	return subject->GetName() + " arrives at " + locationOccured->GetName();
}

void Arrive::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	subject->MoveLocation(locationOccured);

	locationOccured->AddLocationActions(subject);
}

void Arrive::EmotionalReaction(NPC_Actor* affectingActor)
{

}

double Arrive::NPC_CalculateInclination()
{
	return 0;
}

bool Arrive::ReadyToExecute()
{
	if (momentsFromExecution == 0)
	{
		// not really necassary since in most cases travel will tell us our target. but harmless to keep this in case.
		if (!locationOccured){ // if we weren't already given a location we have to find out where we're going.
			// first check if our next action requires a specific location
			if (subject->GetNextPlan()->HasLocation()){
				locationOccured = subject->GetNextPlan()->Get_Location();
			}
			// else check if it need to be done to a target we can travel to.
			else if (subject->GetNextPlan()->HasObject()){
				locationOccured = subject->GetNextPlan()->Get_Object()->GetLocation();
			}
			// else we don't know where were meant to be going, so cancel execution.
			else{
				return false;
			}
		}

		if ((locationOccured == subject->GetLocation())){ // if we're already where we needed to be
			subject->TimeForward();	// move all our plans forward one
			return false;
		}

		return true; // if we got here then our destination is set and we can arrive.
	}

	return false;
}