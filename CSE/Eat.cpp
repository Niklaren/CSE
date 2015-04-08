#include "stdafx.h"
//#include "Eat.h"
#include "Actor.h"
#include "NPC_Actor.h"


Eat::Eat(Actor* subject_, Actor* object_, int moments_ = 1)
	: Action(subject_, moments_)
{
	object = object_;
	Init();
}

Eat::Eat(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
	Init();
}

Eat::Eat()
{
	Init();
}

Eat::~Eat()
{

}

void Eat::Init()
{
	verb = "Eat";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_WolfHungry, WST_bool, false);
	effects.push_back(effect1);

	// conditions
	if (HasObject())
	{
		if (object->GetName() == "You"){
			WorldStateProperty condition1, condition2;
			condition1.SetWSProperty(WSP_RedPanicked, WST_bool, true);
			conditions.push_back(condition1);
			condition2.SetWSProperty(WSP_Location, WST_variable);
			conditions.push_back(condition2);
		}
		if (object->GetName() == "Grandma"){
			WorldStateProperty condition1, condition2;
			condition1.SetWSProperty(WSP_DoorOpen, WST_bool, true);
			conditions.push_back(condition1);
			condition2.SetWSProperty(WSP_Location, WST_variable);
			conditions.push_back(condition2);
		}
	}
	else
	{
		WorldStateProperty condition1;
		condition1.SetWSProperty(WSP_WolfHasLunch, WST_bool, true);
		conditions.push_back(condition1);
	}

}

std::string Eat::GetSentence()
{
	if (HasObject())
		return subject->GetName() + " slurps down " + object->GetName();
	return subject->GetName() + " eats greedily";
}

void Eat::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	//ws->WSProperties[WSP_WolfHungry].SetWSProperty(WSP_WolfHungry, WST_bool, false);

	if (HasObject()){
		if (object->GetName() == "You"){
			ws->WSProperties[WSP_WolfHungry].SetWSProperty(WSP_WolfHungry, WST_bool, false);
			ws->WSProperties[WSP_RedEaten].SetWSProperty(WSP_RedEaten, WST_bool, true);
		}
		if (object->GetName() == "Grandma"){
			//ws->WSProperties[WSP_WolfHungry].SetWSProperty(WSP_WolfHungry, WST_bool, true);
			ws->WSProperties[WSP_GrandmaEaten].SetWSProperty(WSP_GrandmaEaten, WST_bool, true);
		}
	}
}

void Eat::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}

float Eat::NPC_CalculateInclination()
{
	return 0;
}
