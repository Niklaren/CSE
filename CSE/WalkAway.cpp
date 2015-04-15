#include "stdafx.h"
#include "WalkAway.h"
#include "Actor.h"
#include "NPC_Actor.h"


WalkAway::WalkAway(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
	verb = "Walk Away";
}


WalkAway::~WalkAway()
{
}

std::string WalkAway::GetSentence()
{
	return "you start walking away, but it's too late.";
}

void WalkAway::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	subject->RemoveAction("Walk Away");
}

void WalkAway::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
	else
	{
		affectingActor->Change_pAgreeable(-0.2, subject->GetID());
		affectingActor->Change_Happy(-0.2);
	}
}
