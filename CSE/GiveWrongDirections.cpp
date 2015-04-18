#include "stdafx.h"
//#include "GiveWrongDirections.h"
#include "Actor.h"
#include "NPC_Actor.h"


GiveWrongDirections::GiveWrongDirections(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

GiveWrongDirections::GiveWrongDirections()
{
	Init();
}

GiveWrongDirections::~GiveWrongDirections()
{
}

void GiveWrongDirections::Init()
{
	verb = "GiveWrongDirections";

	//effect
	WorldStateProperty effect1, effect2, effect3;
	effect1.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_AskDirections);
	effects.push_back(effect1);
	effect2.SetWSProperty(WSP_WrongDirections, WST_bool, true);
	effects.push_back(effect2);

	// conditions
	WorldStateProperty condition1;
	//condition1.SetWSProperty(WSP_Location, WST_variable);
	//conditions.push_back(condition1);

}

std::string GiveWrongDirections::GetSentence()
{
	if (subject->GetName() == "Wolf")
		return "If you keep going this way I'm sure you'll make it.";
	else
		return "I'm sorry I don't know the way";
}

bool GiveWrongDirections::GetUsable()
{

	return true;
}

void GiveWrongDirections::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	ws->WSProperties[WSP_ReactToWorldStateEvent].SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_AskDirections);
	ws->WSProperties[WSP_WrongDirections].SetValue(true);
}

void GiveWrongDirections::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){

	}
	if (affectingActor == subject){
		affectingActor->Change_Conscientious(-0.05);
	}
}

float GiveWrongDirections::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
	double b = static_cast<NPC_Actor*>(subject)->Get_Conscientious();
	double w = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double result = Blend(-a, -b, w);
	return float(result);
}