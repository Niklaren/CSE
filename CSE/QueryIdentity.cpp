#include "stdafx.h"
//#include "QueryIdentity.h"
#include "Actor.h"
#include "NPC_Actor.h"


QueryIdentity::QueryIdentity(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();
}

QueryIdentity::QueryIdentity()
{
	Init();
}

QueryIdentity::~QueryIdentity()
{

}

void QueryIdentity::Init()
{
	verb = "QueryIdentity";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_QueryRed, WST_int, +1);
	effects.push_back(effect1);

	// conditions
	WorldStateProperty condition1, condition2;
	condition1.SetWSProperty(WSP_WolfGreetRed, WST_bool, true);
	conditions.push_back(condition1);
	//condition2.SetWSProperty(WSP_Location, WST_variable);
	//conditions.push_back(condition2);
}

std::string QueryIdentity::GetSentence()
{
	return "And just who are you then?";
}

void QueryIdentity::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	ws->WSProperties[WSP_QueryRed].ChangeValue(+1);

	object->AddAction("Answer");
	object->AddAction("Ignore");
	object->RemoveAction("Greet");

}

void QueryIdentity::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){
		affectingActor->Change_pAgreeable(-0.05, object->GetID());
	}
}

double QueryIdentity::NPC_CalculateInclination()
{
	return 0;
}
