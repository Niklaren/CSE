#include "stdafx.h"
//#include "Thank.h"
#include "Actor.h"
#include "NPC_Actor.h"


Thank::Thank(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

Thank::Thank()
{
	Init();
}

Thank::~Thank()
{
}

void Thank::Init()
{
	verb = "Thank";

	//effect
	WorldStateProperty effect1, effect2, effect3;
	effect1.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_FoodGiven);
	effects.push_back(effect1);

	// conditions
	WorldStateProperty condition1;
	//condition1.SetWSProperty(WSP_Location, WST_variable);
	//conditions.push_back(condition1);

}

std::string Thank::GetSentence()
{
	if (subject->GetName() == "You"){

	}
	return "Thanks";
}

bool Thank::GetUsable()
{
	if (!(subject->GetHistory()->HaventDoneEventBefore(subject, verb))) // if we've done it before
		return false;
	return true;
}

void Thank::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	subject->RemoveAction("Thank");
}

void Thank::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_pAgreeable(0.05, subject->GetID());
		affectingActor->Change_Happy(0.05);
	}
	if (affectingActor == subject){

	}
}

float Thank::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double b = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
	double w = static_cast<NPC_Actor*>(subject)->Get_Happy();
	double result = Blend(a, b, w);
	result += 0.2;
	return float(result);
}