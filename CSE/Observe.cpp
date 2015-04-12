#include "stdafx.h"
#include "Observe.h"
#include "Actor.h"
#include "NPC_Actor.h"


Observe::Observe(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
}


Observe::~Observe()
{
}

std::string Observe::GetSentence()
{
	if (locationOccured->GetName() == "path")
		return "Despite the pleasant scenery of the woodland\ntrail you can't help but feel uneasy, as if being watched.";
	else if (locationOccured->GetName() == "forest")
		return "The Woods are very Dark here. You're not even sure which way you came from";
	else if (locationOccured->GetName() == "cabin")
		return "You appear to have come across a Lumberjack's Cabin.";
	else if (locationOccured->GetName() == "lodge")
		return "Grandma's Lodge.";

	return "you look about. don't see much";
}

void Observe::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
}

void Observe::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}
