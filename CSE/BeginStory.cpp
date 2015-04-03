#include "stdafx.h"
//#include "BeginStory.h"
#include "Actor.h"
#include "NPC_Actor.h"

//BeginStory::BeginStory()
//{
//	verb = "Begin";
//}

//BeginStory::BeginStory(Actor& subject_)
//{
//	subject = &subject_;
//	verb = "Begin";
//
//}

BeginStory::BeginStory(Actor* subject_, Actor* object_, Actor* extra_, int moments_=0)
	: ActionTargeted(subject_, object_, moments_)
{
	subject = subject_;
	verb = "Begin";
	object = object_;
	extraActor = extra_;
}


BeginStory::~BeginStory()
{
}

void BeginStory::ExecuteConsequences(WorldState* ws)
{

}

//float BeginStory::NPC_CalculateInclination()
//{
//	/*
//	// calculate inclination here
//	//inclination = "Punch";
//
//	//affectingActor
//	affectingActor->Plan("Insult", 1, extraActor);
//	*/
//	return 0;
//}

void BeginStory::EmotionalReaction(NPC_Actor* affectingActor)
{
	/*Goal g;
	g.SetRelevance(0.6f);
	g.SetWSProperty(WSP_FoodEaten, WST_bool, true);
	affectingActor->AddGoal(g);
	*/
}

std::string BeginStory::GetSentence()
{
	return "You arrive late to the campsite. After driving\naround for what seemed forever, you finally\nfound the entrance. You get out of the car\nand see your friend ash come walking over.";
}