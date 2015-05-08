#include "stdafx.h"
//#include "GiveFood.h"
#include "Actor.h"
#include "NPC_Actor.h"


GiveFood::GiveFood(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

GiveFood::GiveFood()
{
	Init();
}

GiveFood::~GiveFood()
{
}

void GiveFood::Init()
{
	verb = "GiveFood" + object->GetName();

}

std::string GiveFood::GetSentence()
{
	if (verb == "GiveFoodWolf")
		return "The wolf looks awfully hungry... you hand over the basket";
	if (verb == "GiveFoodGrandma")
		return "I brought food for you Grandma.";
	if (verb == "GiveFoodLumberjack")
		return "You give the lumberjack your food.";
	return "GiveFood";
}

bool GiveFood::GetUsable()
{
	if (subject->GetHistory()->HaventDoneEventBefore(subject,"GiveFood"))
		return true;
	return false;
}

void GiveFood::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	subject->RemoveAction("Give Food");

	ws->WSProperties[WSP_WolfHasLunch].SetValue(true);

	if (object->GetName() == "Grandma")
		ws->WSProperties[WSP_LunchDelivered].SetValue(true);

}

void GiveFood::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_pAgreeable(0.075, subject->GetID());

		if (object->GetName() == "Grandma")
			affectingActor->Change_pConscientious(0.1, subject->GetID());

		else if (object->GetName() == "Wolf")
			affectingActor->Change_Angry(-0.1);
	}
}