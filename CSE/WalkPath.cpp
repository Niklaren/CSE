#include "stdafx.h"
//#include "WalkPath.h"
#include "Actor.h"

WalkPath::WalkPath(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
	verb = "WalkPath";
}

WalkPath::~WalkPath()
{
}

std::string WalkPath::GetSentence()
{
	return "after walking down the path a bit you think you see grandma's lodge.";
}

bool WalkPath::GetUsable()
{
	return true;
}

void WalkPath::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	
	subject->AddLocation("lodge");
}

void WalkPath::EmotionalReaction(NPC_Actor* affectingActor)
{

}