#include "stdafx.h"
//#include "CookGood.h"
#include "Actor.h"
#include "NPC_Actor.h"


CookGood::CookGood(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{

	Init();
}

CookGood::CookGood()
{
	Init();
}

CookGood::~CookGood()
{

}

void CookGood::Init()
{
	verb = "CookGood";

	//effects
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_FoodCooked, WST_bool, true);
	effects.push_back(effect1);

	// conditions
	// same location?
	WorldStateProperty condition1;
	condition1.SetWSProperty(WSP_StoveReady, WST_bool, true);
	conditions.push_back(condition1);

}

std::string CookGood::GetSentence()
{
	return subject->GetName() + " prepares a fine meal.";
}

void CookGood::ExecuteConsequences(WorldState* ws)
{
	ws->WSProperties[WSP_FoodCooked].SetWSProperty(WSP_FoodCooked, WST_bool, true);

	//if wood is good and water is enough
	//quality is high
	//else quality is low
}

void CookGood::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}

float CookGood::NPC_CalculateInclination()
{
	return 0;
}