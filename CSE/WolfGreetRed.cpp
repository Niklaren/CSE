#include "stdafx.h"
//#include "WolfGreetRed.h"
#include "Actor.h"
#include "NPC_Actor.h"


WolfGreetRed::WolfGreetRed(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

WolfGreetRed::WolfGreetRed()
{
	Init();
}

WolfGreetRed::~WolfGreetRed()
{
}

void WolfGreetRed::Init()
{
	verb = "WolfGreetRed";

	//effect
	WorldStateProperty effect1, effect2, effect3;
	effect1.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Greet);
	effects.push_back(effect1);
	effect2.SetWSProperty(WSP_WolfGreetRed, WST_bool, true);
	effects.push_back(effect2);

	// conditions
	WorldStateProperty condition1;
	//condition1.SetWSProperty(WSP_Location, WST_variable);
	//conditions.push_back(condition1);

}

std::string WolfGreetRed::GetSentence()
{
	return "A Wolf comes towards you through the trees. He speaks:\nhail stranger, odd to see someone travelling alone through here.";
}

bool WolfGreetRed::GetUsable()
{
	if (!(subject->GetHistory()->HaventDoneEventBefore(subject, verb))) // if we've done it before
		return false;
	return true;
}

void WolfGreetRed::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	ws->WSProperties[WSP_WolfGreetRed].SetValue(true);
}

void WolfGreetRed::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		
	}
	if (affectingActor == subject){
		affectingActor->AddAction("Intimidate", object);
	}
}

float WolfGreetRed::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double b = static_cast<NPC_Actor*>(subject)->Get_pPAgreeable();
	double w = static_cast<NPC_Actor*>(subject)->Get_Happy();
	double result = Blend(a, b, w);
	return float(result);
}