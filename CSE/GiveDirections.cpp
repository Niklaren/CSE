#include "stdafx.h"
//#include "GiveDirections.h"
#include "Actor.h"
#include "NPC_Actor.h"


GiveDirections::GiveDirections(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

GiveDirections::GiveDirections()
{
	Init();
}

GiveDirections::~GiveDirections()
{
}

void GiveDirections::Init()
{
	verb = "GiveDirections";

	//effect
	WorldStateProperty effect1, effect2, effect3;
	effect1.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_AskDirections);
	effects.push_back(effect1);
	//effect2.SetWSProperty(WSP_GiveDirections, WST_bool, true);
	//effects.push_back(effect2);

	// conditions
	WorldStateProperty condition1;
	//condition1.SetWSProperty(WSP_Location, WST_variable);
	//conditions.push_back(condition1);

}

std::string GiveDirections::GetSentence()
{
	if (subject->GetName() == "Wolf")
		return "Well, there's a lodge back down th path if you turn back.";
	else
		return "Head out down that path, its not too far";
}

bool GiveDirections::GetUsable()
{
	return true;
}

void GiveDirections::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	ws->WSProperties[WSP_ReactToWorldStateEvent].SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_AskDirections);
	
	if (object->GetName() == "You" && subject->GetName() == "Lumberjack")
		object->AddAction("Go To Lodge");
}

void GiveDirections::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){

	}
	if (affectingActor == subject){
		affectingActor->Change_Conscientious(0.05);
	}
}

float GiveDirections::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Conscientious();
	double b = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double w = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
	double result = Blend(a, b, w);
	return float(result);
}