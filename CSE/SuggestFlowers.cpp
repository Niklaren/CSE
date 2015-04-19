#include "stdafx.h"
//#include "SuggestFlowers.h"
#include "Actor.h"
#include "NPC_Actor.h"


SuggestFlowers::SuggestFlowers(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

SuggestFlowers::SuggestFlowers()
{
	Init();
}

SuggestFlowers::~SuggestFlowers()
{
}

void SuggestFlowers::Init()
{
	verb = "SuggestFlowers";

	//effect
	WorldStateProperty effect1, effect2, effect3;
	effect1.SetWSProperty(WSP_RedDistracted, WST_bool, true);
	effects.push_back(effect1);

	// conditions
	WorldStateProperty condition1;

}

std::string SuggestFlowers::GetSentence()
{
	return "wouldn't it be nice to pick some flowers to give to your grandmother?";
}

bool SuggestFlowers::GetUsable()
{
	if (!(subject->GetHistory()->HaventDoneEventBefore(subject, verb))) // if we've done it before
		return false;
	return true;
}

void SuggestFlowers::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	//object->AddAction("Pick Flowers");
	ws->WSProperties[WSP_RedDistracted].SetValue(true);
}

void SuggestFlowers::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_Open(0.05);
	}
	if (affectingActor == subject){
		affectingActor->Change_Open(0.05);
		affectingActor->Change_Extraverted(0.05);
	}
}

float SuggestFlowers::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Extraverted();
	double b = static_cast<NPC_Actor*>(subject)->Get_Open();
	double result = a + b + 0.15;
	return float(result);
}