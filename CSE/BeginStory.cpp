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
	: Action(moments_)
{
	subject = subject_;
	verb = "Begin";
	object = object_;
	extraActor = extra_;
}


BeginStory::~BeginStory()
{
}

void BeginStory::NPC_CalculateInclination(NPC_Actor* affectingActor)
{
	std::string inclination;

	// calculate inclination here
	inclination = "Punch";

	//affectingActor
	affectingActor->Plan("Insult", extraActor);

	return;
}

void BeginStory::EmotionalReaction(NPC_Actor* reactingActor)
{

}

std::string BeginStory::GetSentence()
{
	return "Once upon a time";
}