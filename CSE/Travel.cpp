#include "stdafx.h"
//#include "Travel.h"
#include "Actor.h"
#include "NPC_Actor.h"

// travel to a yet to be known location. figure out where based on our next plan.
Travel::Travel(Actor* subject_, int moments_)
	: Action(subject_, moments_)
{
	Init();
	verb = "Travel";
}

Travel::Travel(Actor* subject_, Stage* s, int moments_, string v)
	: Action(subject_, moments_)
{
	targetLocation = s;
	Init();
	verb = v;
}

Travel::Travel()
{
	Init();
	verb = "Travel";
}

Travel::~Travel()
{

}

void Travel::Init()
{
	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_Location, WST_variable);
	effects.push_back(effect1);

	// conditions

}

std::string Travel::GetSentence()
{
	return subject->GetName() + " leaves the area.";
}

void Travel::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	//subject->Plan("Leave", locationOccured); // could have leave action. but travel serves same purpose. so no need.
	subject->Plan("Arrive", targetLocation, 0); //travel forces an arrive event to occur simultaneously.

	locationOccured->RemoveLocationActions(subject);


}

void Travel::EmotionalReaction(NPC_Actor* affectingActor)
{

}

float Travel::NPC_CalculateInclination()
{
	return 0;
}

bool Travel::ReadyToExecute()
{
	if (momentsFromExecution == 0)
	{
		if (!targetLocation){// if we weren't already given a location we have to find out where we're going.
			// first check if our next action requires a specific location
			if (subject->GetNextPlan()->HasLocation()){
				targetLocation = subject->GetNextPlan()->Get_Location();
			}
			// else check if it need to be done to a target we can travel to.
			else if (subject->GetNextPlan()->HasObject()){
				targetLocation = subject->GetNextPlan()->Get_Object()->GetLocation();
			}
			// else we don't know where were meant to be going, so cancel execution.
			else{
				return false;
			}
		}

		if ((targetLocation == subject->GetLocation())){ // if we're already there.
			subject->TimeForward();	// move all our plans forward one
			return false;
		}

		return true; // if we got here then our location is set and we can go.
	}

	return false;
}