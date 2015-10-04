#include "stdafx.h"
//#include "WolfEatLunch.h"
#include "Actor.h"
#include "NPC_Actor.h"


WolfEatLunch::WolfEatLunch(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
	Init();
}

WolfEatLunch::WolfEatLunch()
{
	Init();
}

WolfEatLunch::~WolfEatLunch()
{

}

void WolfEatLunch::Init()
{
	verb = "WolfEatLunch";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_WolfHungry, WST_bool, false);
	effects.push_back(effect1);

	// conditions
	WorldStateProperty condition1;
	condition1.SetWSProperty(WSP_WolfHasLunch, WST_bool, true);
	conditions.push_back(condition1);

}

std::string WolfEatLunch::GetSentence()
{
	return "The Wolf Eats the contents greedily";
}

void WolfEatLunch::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	//ws->WSProperties[WSP_WolfHungry].SetWSProperty(WSP_WolfHungry, WST_bool, false);
	ws->WSProperties[WSP_WolfHungry].SetValue(false);
}

void WolfEatLunch::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){
		affectingActor->Change_Happy(0.1);
	}
}

// no personality associated with eating lunch. just something we are happy to do.
double WolfEatLunch::NPC_CalculateInclination()
{
	return 0.3;
}
