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
	if (subject->GetHistory()->EventJustHappened("Travel"))
		return "you walk away from the wolf";
	if (subject->GetHistory()->EventJustHappened("WolfEatYou"))
		return "You try to walk away, but it's too late";
	return "you start walking away, but the wolf follows.";
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
