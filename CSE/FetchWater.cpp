#include "stdafx.h"
//#include "FetchWater.h"
#include "Actor.h"
#include "NPC_Actor.h"


FetchWater::FetchWater(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{

	Init();
}

FetchWater::FetchWater()
{
	Init();
}

FetchWater::~FetchWater()
{

}

void FetchWater::Init()
{
	verb = "FetchWater";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_WaterFetched, WST_int, 1); // switch this to a +1
	effects.push_back(effect1);

	// conditions
	// location?

}

std::string FetchWater::GetSentence()
{
	return subject->GetName() + " fetches a pail of water to cook with";
}

void FetchWater::ExecuteConsequences(WorldState* ws)
{
	ws->WSProperties[WSP_WaterFetched].SetWSProperty(WSP_WaterFetched, WST_int, 1); // switch this to a +1

}

void FetchWater::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}

float FetchWater::NPC_CalculateInclination()
{
	return 0;
}
