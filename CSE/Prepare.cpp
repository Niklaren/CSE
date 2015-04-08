#include "stdafx.h"
#include "Prepare.h"
#include "NPC_Actor.h"

Prepare::Prepare(Actor* subject_, int moments_)
	:Action(subject_, moments_)
{
	verb = "Prepare";
}

Prepare::Prepare()
{
}


Prepare::~Prepare()
{
}

void Prepare::ExecuteConsequences(WorldState* ws)
{
	//Goal g;
	//g.SetRelevance(0.6f);
	//g.SetWSProperty(WSP_FoodEaten, WST_bool, true);
	//subject->AddGoal(g);  //doesnt know subject is an npc
}

void Prepare::EmotionalReaction(NPC_Actor* affectingActor)
{

}

std::string Prepare::GetSentence()
{
	return "Well, we've stood here chatting for long enough.\nYou were already late and it will be dark soon.\nAsh suggests we get some food prepared.";

}