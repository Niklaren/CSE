#include "stdafx.h"
//#include "QueryBasket.h"
#include "Actor.h"
#include "NPC_Actor.h"


QueryBasket::QueryBasket(Actor* subject_, Actor* object_, int moments_ = 1)
	: Action(subject_, moments_)
{
	object = object_;
	Init();
}

QueryBasket::QueryBasket()
{
	Init();
}

QueryBasket::~QueryBasket()
{

}

void QueryBasket::Init()
{
	verb = "QueryBasket";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_QueryRed, WST_bool, true);
	effects.push_back(effect1);

	// conditions
	WorldStateProperty condition1, condition2;
	condition1.SetWSProperty(WSP_WolfGreetRed, WST_bool, true);
	conditions.push_back(condition1);
	condition2.SetWSProperty(WSP_Location, WST_variable);
	conditions.push_back(condition2);
}

std::string QueryBasket::GetSentence()
{
	return "What's in the basket? food?";
}

void QueryBasket::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	ws->WSProperties[WSP_QueryRed].SetWSProperty(WSP_QueryRed, WST_bool, true);

	subject->AddAction("ReplyBasket");

}

void QueryBasket::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}

float QueryBasket::NPC_CalculateInclination()
{
	return 0;
}
