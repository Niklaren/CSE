#include "stdafx.h"
//#include "AgreeEscort.h"
#include "Actor.h"
#include "NPC_Actor.h"


AgreeEscort::AgreeEscort(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

AgreeEscort::AgreeEscort()
{
	Init();
}

AgreeEscort::~AgreeEscort()
{
}

void AgreeEscort::Init()
{
	verb = "AgreeEscort";

	//effect
	WorldStateProperty effect1, effect2, effect3;
	effect1.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_RequestEscort);
	effects.push_back(effect1);
	//effect2.SetWSProperty(WSP_AgreeEscort, WST_bool, true);
	//effects.push_back(effect2);

	// conditions
	WorldStateProperty condition1;
	//condition1.SetWSProperty(WSP_Location, WST_variable);
	//conditions.push_back(condition1);

}

std::string AgreeEscort::GetSentence()
{
	return "The Lumberjack thinks for a moment, then agrees to go with you to be sure you're safe.";
}

void AgreeEscort::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	ws->WSProperties[WSP_ReactToWorldStateEvent].SetValue(WSE_RequestEscort);
	ws->WSProperties[WSP_HaveEscort].SetValue(true);

	object->AddAction("Go To Lodge");
	object->RemoveAction("Ask Directions");
}

void AgreeEscort::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){

	}
	if (affectingActor == subject){
		affectingActor->Change_Conscientious(0.05);
		affectingActor->Change_Open(0.05);

		affectingActor->RemoveGoal("ChopLumber");
	}
}

double AgreeEscort::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Conscientious();
	double b = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
	double w = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double result = Blend(a, b, w) - 0.5f /*for travel*/;
	return result;
}