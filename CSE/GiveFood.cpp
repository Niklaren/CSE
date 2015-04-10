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
	verb = "GiveFood";

}

std::string GiveFood::GetSentence()
{
	if (object->GetName() == "Wolf")
		return "The wolf looks awfully hungry...";
	if (object->GetName() == "Grandma")
		return "i brought food for you Grandma.";
	if (object->GetName() == "Lumberjack")
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

	subject->RemoveAction("GiveFood");

	if (object->GetName() == "Wolf"){
		ws->WSProperties[WSP_WolfHasLunch].SetValue(true);
		ws->WSProperties[WSP_WolfHungry].SetValue(false);
	}
	if (object->GetName() == "Grandma")
		ws->WSProperties[WSP_LunchDelivered].SetValue(true);

}

void GiveFood::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}