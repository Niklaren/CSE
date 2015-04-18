#include "stdafx.h"
//#include "RefuseEscort.h"
#include "Actor.h"
#include "NPC_Actor.h"


RefuseEscort::RefuseEscort(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

RefuseEscort::RefuseEscort()
{
	Init();
}

RefuseEscort::~RefuseEscort()
{
}

void RefuseEscort::Init()
{
	verb = "RefuseEscort";

	//effect
	WorldStateProperty effect1, effect2, effect3;
	effect1.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_RequestEscort);
	effects.push_back(effect1);

	// conditions
	WorldStateProperty condition1;
	//condition1.SetWSProperty(WSP_Location, WST_variable);
	//conditions.push_back(condition1);

}

std::string RefuseEscort::GetSentence()
{
	return "Sorry, I'm a little busy right now.";
}


void RefuseEscort::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	ws->WSProperties[WSP_ReactToWorldStateEvent].SetValue(WSE_RequestEscort);

}

void RefuseEscort::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){

	}
	if (affectingActor == subject){
		affectingActor->Change_Conscientious(-0.05);
	}
}

float RefuseEscort::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());	// how they like the target
	double b = static_cast<NPC_Actor*>(subject)->Get_Conscientious();				// how lazy
	double w = static_cast<NPC_Actor*>(subject)->Get_Extraverted();					// weighted by how shy
	double result = Blend(-a, -b, w);
	return float(result);
}