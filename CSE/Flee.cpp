#include "stdafx.h"
#include "Flee.h"
#include "NPC_Actor.h"

Flee::Flee(Actor* subject_, Stage* s, int moments_ = 1)
	: Action(subject_, moments_)
{
	verb = "Flee";
	fleeTo = s;
}


Flee::~Flee()
{
}


std::string Flee::GetSentence()
{
	return "You ran as fast as you can from the wolf";
}

void Flee::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	subject->RemoveAction("Flee");
	//ws->WSProperties[WSP_RedPanicked].SetValue(false);
	ws->WSProperties[WSP_RedDistracted].SetValue(true);

	subject->Plan("Travel", fleeTo);
}

void Flee::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){
		affectingActor->Plan("Arrive", fleeTo);
	}
	if (affectingActor->GetName() == "Wolf"){
		affectingActor->RemoveAction("WolfEatYou");
		affectingActor->ClearPlans();
		
	}
	
}
