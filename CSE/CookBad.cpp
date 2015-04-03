#include "stdafx.h"
//#include "CookBad.h"
#include "Actor.h"
#include "NPC_Actor.h"


CookBad::CookBad(Actor* subject_, int moments_ = 1)
	: Action(moments_)
{
	subject = subject_;
	//object = object_;

	Init();
}

CookBad::CookBad()
{
	Init();
}

CookBad::~CookBad()
{

}

void CookBad::Init()
{
	verb = "CookBad";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_FoodCooked, WST_bool, true);
	effects.push_back(effect1);

	// conditions
	// same location as target??
	WorldStateProperty condition1;
	condition1.SetWSProperty(WSP_StoveReady, WST_bool, true);
	conditions.push_back(condition1);

}

std::string CookBad::GetSentence()
{
	return subject->GetName() + " struggles to prepare a sparse meal.";
}

void CookBad::ExecuteConsequences(WorldState* ws)
{
	ws->WSProperties[WSP_FoodCooked].SetWSProperty(WSP_FoodCooked, WST_bool, true);

}

void CookBad::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){

	}
	if (affectingActor == subject){

	}
}

void CookBad::NPC_CalculateInclination(NPC_Actor* affectingActor)
{

}