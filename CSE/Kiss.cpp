#include "stdafx.h"
//#include "Kiss.h"
#include "Actor.h"
#include "NPC_Actor.h"


Kiss::Kiss(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

Kiss::Kiss()
{
	Init();
}

Kiss::~Kiss()
{
}

void Kiss::Init()
{
	verb = "Kiss";

	//effect
	WorldStateProperty effect1, effect2, effect3;
	effect2.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Hug);
	effects.push_back(effect2);

	// conditions
	WorldStateProperty condition1;
	//condition1.SetWSProperty(WSP_Location, WST_variable);
	//conditions.push_back(condition1);

}

std::string Kiss::GetSentence()
{
	if (subject->GetName() == "Grandma")
			return "grandma gives you a wet kiss.";

	return "Kissings";
}

bool Kiss::GetUsable()
{
	if (!(subject->GetHistory()->HaventDoneEventBefore(subject, verb))) // if we've done it before
		return false;
	return true;
}

void Kiss::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	subject->RemoveAction("Kiss");
	ws->WSProperties[WSP_ReactToWorldStateEvent].SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Hug);
}

void Kiss::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_Happy(affectingActor->Get_pAgreeable(subject->GetID()) / 5);
		affectingActor->Change_pAgreeable(0.2, subject->GetID());
		affectingActor->Change_Agreeable(0.01);
	}
	if (affectingActor == subject){

	}
}

float Kiss::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
	double b = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double w = static_cast<NPC_Actor*>(subject)->Get_Extraverted();;
	double result = Blend(a, b, w);
	return float(result);
}