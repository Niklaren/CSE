#include "stdafx.h"
//#include "WolfEat.h"
#include "Actor.h"
#include "NPC_Actor.h"


WolfEat::WolfEat(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	object = object_;
	Init();
}

WolfEat::WolfEat()
{
	Init();
}

WolfEat::~WolfEat()
{

}

void WolfEat::Init()
{
	verb = "WolfEat" + object->GetName();

	// eating solves the wolf hungry goal.
	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_WolfHungry, WST_bool, false);
	effects.push_back(effect1);

	// conditions
	if (verb == "WolfEatYou"){
		WorldStateProperty condition1, condition2;
		condition1.SetWSProperty(WSP_RedPanicked, WST_bool, true);
		conditions.push_back(condition1);

	}
	else if (verb == "WolfEatGrandma"){
		WorldStateProperty condition1, condition2;
		condition1.SetWSProperty(WSP_DoorOpen, WST_bool, true);
		conditions.push_back(condition1);

	}
}

std::string WolfEat::GetSentence()
{
	if (HasObject()){
		if (object->GetName() == "Wolf"){
			return "The wolf closes in on you. And eats you down.";
		}
		else
		{
			return subject->GetName() + " slurps down " + object->GetName();
		}
	}
		
	return "Wolf Eats greedily";
}

void WolfEat::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	//ws->WSProperties[WSP_WolfHungry].SetWSProperty(WSP_WolfHungry, WST_bool, false);

	if (verb == "WolfEatYou"){
		ws->WSProperties[WSP_WolfHungry].SetValue(false);
		ws->WSProperties[WSP_RedEaten].SetValue(true);
	}
	if (verb == "WolfEatGrandma"){
		ws->WSProperties[WSP_WolfHungry].SetValue(false);
		ws->WSProperties[WSP_GrandmaEaten].SetValue(true);
	}
}

void WolfEat::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){
		affectingActor->Change_Open(-0.1);
	}
	if (affectingActor == object){
		// not much point since they're dead now.
	}
}

// different inclination depending on target. could use the same formula.
// but a calmer more conniving character would pick the easier meal (grandma). if he's angry he'll go for the target in front.
float WolfEat::NPC_CalculateInclination()
{
	if (verb == "WolfEatYou"){
		double a = static_cast<NPC_Actor*>(subject)->Get_Angry();
		double b = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
		double result = Blend(a, -b, 0);
		return float(result);
	}
	if (verb == "WolfEatGrandma"){
		double a = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
		double b = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
		double result = Blend(-a, -b, 0);
		return float(result);
	}
	return 0;
}
