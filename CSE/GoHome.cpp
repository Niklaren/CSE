#include "stdafx.h"
#include "GoHome.h"
#include "Actor.h"
#include "NPC_Actor.h"


GoHome::GoHome(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
}


GoHome::~GoHome()
{
}

std::string GoHome::GetSentence()
{
	return "Time to go home, you think.";
}

void GoHome::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	ws->WSProperties[WSP_RedHome].SetValue(true);
}

void GoHome::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}
