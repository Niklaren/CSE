#include "stdafx.h"
//#include "GiveFlowers.h"
#include "Actor.h"
#include "NPC_Actor.h"


GiveFlowers::GiveFlowers(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

GiveFlowers::GiveFlowers()
{
	Init();
}

GiveFlowers::~GiveFlowers()
{
}

void GiveFlowers::Init()
{
	verb = "Give Flowers";

}

std::string GiveFlowers::GetSentence()
{
	if (object->GetName() ==  "Grandma")
		return "I brought Flowers for you Grandma.";
	if (object->GetName() == "Lumberjack")
		return "You give the lumberjack the Flowers.";
	return "Give Flowers";
}

bool GiveFlowers::GetUsable()
{
	//if (ws->WSProperties[WSP_HaveFlowers].bvalue == true)
		return true;
	//return false;
}

void GiveFlowers::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	subject->RemoveAction("Give Flowers");

	ws->WSProperties[WSP_HaveFlowers].SetValue(false);

}

void GiveFlowers::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_pAgreeable(0.2, subject->GetID());
		affectingActor->Change_Happy(0.2);
		affectingActor->Change_Agreeable(0.05);
		affectingActor->Change_Extraverted(0.02);
	}
}