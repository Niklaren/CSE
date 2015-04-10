#include "stdafx.h"
//#include "Travel.h"
#include "Actor.h"
#include "NPC_Actor.h"


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
	return subject->GetName() + " moves to " + targetLocation->GetName();
}

void Travel::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	//ws->WSProperties[WSP_Location].SetWSProperty(WSP_Location, WST_variable);

	//if ((!targetLocation) && (subject->GetNextPlan()->HasObject())){
	//	targetLocation = subject->GetNextPlan()->Get_Object()->GetLocation();
	//}
	//else if ((!targetLocation) && (subject->GetNextPlan()->HasLocation())){
	//	targetLocation = subject->GetNextPlan()->Get_Location();
	//}

	//subject->removeactions location actions
	locationOccured->RemoveLocationActions(subject);

	subject->MoveLocation(targetLocation);

	//subject->addactions location actions
	targetLocation->AddLocationActions(subject);
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
		if (!targetLocation){
			if (subject->GetNextPlan()->HasLocation()){
				targetLocation = subject->GetNextPlan()->Get_Location();
			}
			else if (subject->GetNextPlan()->HasObject()){
				targetLocation = subject->GetNextPlan()->Get_Object()->GetLocation();
			}
			else{
				return false;
			}
		}

		if ((targetLocation == subject->GetLocation())){
			subject->TimeForward();	// move all our plans forward one
			return false;
		}

		return true;
	}

	return false;
}