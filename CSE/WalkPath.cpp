#include "stdafx.h"
//#include "WalkPath.h"
#include "Actor.h"

WalkPath::WalkPath(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
	verb = "WalkPath";
}

WalkPath::WalkPath()
{

	WorldStateProperty effect0;
	//effect0.SetWSProperty(WSP_Greeting, WST_bool, true);

	//no conditions
}

WalkPath::~WalkPath()
{
}

std::string WalkPath::GetSentence()
{
	return "no response.";
}

bool WalkPath::GetUsable()
{
	return true;
}

void WalkPath::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	//subject->AddLocation(lodge)
}

void WalkPath::NPC_EmotionalReaction(NPC_Actor* affectingActor)
{

}