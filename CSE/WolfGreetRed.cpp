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
	return "A Wolf comes towards you through the trees. He speaks: hello stranger. Odd to see someone travelling alone through here.";
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

	subject->RemoveAction("WolfGreetRed");
	
}

void WolfGreetRed::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		
	}
	if (affectingActor == subject){
		affectingActor->Change_Happy(0.025);
		affectingActor->AddAction("Intimidate", object);
	}
}

// inclination to greet depends on how nice we are and how nice we think the other person to be.
// if we're in a bad mood then higher weighting will be on our internal niceness. if we're nice we'greet anyway. if we're in a bad mood
// and we're not nice we definitely dont want to do it. if we're in a good mood then it depends more on how the target is liked.
double WolfGreetRed::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double b = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
	double w = static_cast<NPC_Actor*>(subject)->Get_Happy();
	double result = Blend(a, b, w);
	return result;
}