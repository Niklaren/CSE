#include "stdafx.h"
//#include "FetchWood.h"
#include "Actor.h"
#include "NPC_Actor.h"


FetchWood::FetchWood(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
	Init();
}

FetchWood::FetchWood()
{
	Init();
}

FetchWood::~FetchWood()
{

}

void FetchWood::Init()
{
	verb = "FetchWood";

	//effects
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_WoodCollected, WST_bool, true);
	effects.push_back(effect1);

	// conditions
	// same location?

}

std::string FetchWood::GetSentence()
{
	return subject->GetName() + " Fetches some firewood from the nearby forest.";
}

void FetchWood::ExecuteConsequences(WorldState* ws)
{
	ws->WSProperties[WSP_WoodCollected].SetWSProperty(WSP_WoodCollected, WST_bool, true);
}

void FetchWood::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}

float FetchWood::NPC_CalculateInclination()
{
	return 0;
}