#include "stdafx.h"
//#include "BuildStove.h"
#include "Actor.h"
#include "NPC_Actor.h"


BuildStove::BuildStove(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
	//subject = subject_;
	//object = object_;

	Init();
}

BuildStove::BuildStove()
{
	Init();
}

BuildStove::~BuildStove()
{

}

void BuildStove::Init()
{
	verb = "BuildStove";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_StoveReady, WST_bool, true);
	effects.push_back(effect1);

	// conditions
	// location?
	WorldStateProperty condition1, condition2, condition3;
	condition1.SetWSProperty(WSP_Unpacked, WST_bool, true);
	conditions.push_back(condition1);
	condition2.SetWSProperty(WSP_WoodCollected, WST_bool, true);
	conditions.push_back(condition2);
	condition3.SetWSProperty(WSP_WaterFetched, WST_int, 1); // switch this to a > 1
	conditions.push_back(condition3);

}

std::string BuildStove::GetSentence()
{
	return subject->GetName() + " hangs the pot over the fire and begins heating the water.";
}

void BuildStove::ExecuteConsequences(WorldState* ws)
{
	ws->WSProperties[WSP_StoveReady].SetWSProperty(WSP_StoveReady, WST_bool, true);
}

void BuildStove::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}

float BuildStove::NPC_CalculateInclination()
{
	return 0;
}
