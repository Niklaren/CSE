#include "stdafx.h"
//#include "Eat.h"
#include "Actor.h"
#include "NPC_Actor.h"


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
	effect1.SetWSProperty(WSP_FoodEaten, WST_bool, true);
	effects.push_back(effect1);

	// conditions
	// same location as target??
	WorldStateProperty condition1;
	condition1.SetWSProperty(WSP_FoodCooked, WST_bool, true);
	conditions.push_back(condition1);

}

std::string Eat::GetSentence()
{
	return subject->GetName() + " eats the food heartily.";
}

void Eat::ExecuteConsequences(WorldState* ws)
{
	ws->WSProperties[WSP_FoodEaten].SetWSProperty(WSP_FoodEaten, WST_bool, true);

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
