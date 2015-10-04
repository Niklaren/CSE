#include "stdafx.h"
//#include "KillWolf.h"
#include "Actor.h"
#include "NPC_Actor.h"


KillWolf::KillWolf(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	object = object_;
	Init();
}

KillWolf::KillWolf()
{
	Init();
}

KillWolf::~KillWolf()
{

}

void KillWolf::Init()
{
	verb = "KillWolf";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_WolfDead, WST_bool, true);
	effects.push_back(effect1);

	// conditions
	//condition2.SetWSProperty(WSP_Location, WST_variable);
	//conditions.push_back(condition2);
}

std::string KillWolf::GetSentence()
{
	return "The Lumberjack slices the wolf with his axe, killing it.";
}

void KillWolf::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	ws->WSProperties[WSP_WolfDead].SetValue(true);

}

void KillWolf::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}

double KillWolf::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
	double b = static_cast<NPC_Actor*>(subject)->Get_Angry();
	double result = Blend(-a, b, 0);
	return -result;
}
