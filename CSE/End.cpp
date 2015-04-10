#include "stdafx.h"
//#include "End.h"
#include "Actor.h"
#include "NPC_Actor.h"


End::End(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
}


End::~End()
{
}

std::string End::GetSentence()
{
	return "The End";
}

void End::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
}

void End::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}
