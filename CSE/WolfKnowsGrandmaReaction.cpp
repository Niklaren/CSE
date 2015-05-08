#include "stdafx.h"
//#include "WolfKnowsGrandmaReaction.h"
#include "Actor.h"
#include "NPC_Actor.h"


WolfKnowsGrandmaReaction::WolfKnowsGrandmaReaction(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
	Init();
}

WolfKnowsGrandmaReaction::WolfKnowsGrandmaReaction()
{
	Init();
}

WolfKnowsGrandmaReaction::~WolfKnowsGrandmaReaction()
{

}

void WolfKnowsGrandmaReaction::Init()
{
	verb = "WolfKnowsGrandmaReaction";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_WolfKnowsGrandma);
	effects.push_back(effect1);

	// conditions
	WorldStateProperty condition1;
	// no condition

}

std::string WolfKnowsGrandmaReaction::GetSentence()
{
	return "The wolf's ears prick slightly. 'Grandma you say?'";
}

void WolfKnowsGrandmaReaction::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	ws->WSProperties[WSP_ReactToWorldStateEvent].SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_WolfKnowsGrandma);

	subject->RemoveAction("WolfKnowsGrandmaReaction");
}


