#include "stdafx.h"
//#include "Forgive.h"
#include "Actor.h"
#include "NPC_Actor.h"


Forgive::Forgive(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

Forgive::Forgive()
{
	Init();
}

Forgive::~Forgive()
{
}

void Forgive::Init()
{
	verb = "Forgive";

	//effect
	WorldStateProperty effect1, effect2, effect3;
	effect2.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Apologize);
	effects.push_back(effect2);

	// conditions
	WorldStateProperty condition1;
	//condition1.SetWSProperty(WSP_Location, WST_variable);
	//conditions.push_back(condition1);

}

std::string Forgive::GetSentence()
{
	return "She forgives you";
}

bool Forgive::GetUsable()
{
	if (!(subject->GetHistory()->HaventDoneEventBefore(subject, verb))) // if we've done it before
		return false;
	return true;
}

void Forgive::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	subject->RemoveAction("Forgive");
	subject->RemoveAction("Reprimand");
	ws->WSProperties[WSP_ReactToWorldStateEvent].SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Apologize);
	ws->WSProperties[WSP_Forgiven].SetValue(true);
}

void Forgive::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_Angry(-0.1);
	}
	if (affectingActor == subject){

	}
}

// unlikey to forgive if angry or dislikes you.
float Forgive::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Angry();
	double b = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
	double w = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double result = Blend(-a, b, w);
	return float(result);
}