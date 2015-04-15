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

float Arrive::NPC_CalculateInclination()
{
	return 0;
}

bool Arrive::ReadyToExecute()
{
	if (momentsFromExecution == 0)
	{
		if (!locationOccured){
			if (subject->GetNextPlan()->HasLocation()){
				locationOccured = subject->GetNextPlan()->Get_Location();
			}
			else if (subject->GetNextPlan()->HasObject()){
				locationOccured = subject->GetNextPlan()->Get_Object()->GetLocation();
			}
			else{
				return false;
			}
		}

		if ((locationOccured == subject->GetLocation())){
			subject->TimeForward();	// move all our plans forward one
			return false;
		}

		return true;
	}

	return false;
}