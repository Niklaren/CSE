#include "stdafx.h"
//#include "PickFlowers.h"
#include "Actor.h"
#include "NPC_Actor.h"


PickFlowers::PickFlowers(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
	verb = "Pick Flowers";
}


PickFlowers::~PickFlowers()
{
}

std::string PickFlowers::GetSentence()
{

	return "You spend a little time choosing & picking the nicest flowers.";
}

void PickFlowers::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	ws->WSProperties[WSP_HaveFlowers].SetValue(true);
	//subject->AddAction("Give Flowers");
	subject->RemoveAction("Pick Flowers");
}

void PickFlowers::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}
