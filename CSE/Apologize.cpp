#include "stdafx.h"
//#include "Apologize.h"
#include "Actor.h"
#include "NPC_Actor.h"


Apologize::Apologize(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

Apologize::Apologize()
{
	Init();
}

Apologize::~Apologize()
{
}

void Apologize::Init()
{
	verb = "Apologize";

	//effect
	WorldStateProperty effect1, effect2;
	//effect1.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Apologize);
	//effects.push_back(effect1);


	// conditions
	// none

}

std::string Apologize::GetSentence()
{
	if (subject->GetName() == "You"){
		return "I'm sorry I was so late, I got totally lost.\nWhere is this place?";
	}
	return subject->GetName() + " Apologizes";
}

bool Apologize::GetUsable()
{
	if (!(subject->historyBook->HaventDoneEventBefore(subject, verb))) // if we've done it before
		return false;
	if (subject->historyBook->TimeSinceStart() > 5) // if we've moved passed Apologizeing stage
		return false;
	return true;
}

void Apologize::ExecuteConsequences(WorldState* ws)
{

}

void Apologize::EmotionalReaction(NPC_Actor* affectingActor)
{

	if (affectingActor == object){
		Goal g;
		g.SetRelevance(0.7f);
		g.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Apologize);
		affectingActor->AddGoal(g);
	}
	if (affectingActor == subject){

	}
}

float Apologize::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double b = static_cast<NPC_Actor*>(subject)->Get_pPAgreeable();
	double w = static_cast<NPC_Actor*>(subject)->Get_Happy();
	double result = Blend(a, b, w);
	return float(result);
}