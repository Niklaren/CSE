#include "stdafx.h"
//#include "Greet.h"
#include "Actor.h"
#include "NPC_Actor.h"


Greet::Greet(Actor* subject_, Actor* object_, int moments_ = 1)
	: Action(moments_)
{
	subject = subject_;
	verb = "Greets";
	object = object_;
}


Greet::~Greet()
{
}

void Greet::NPC_CalculateInclination(NPC_Actor* affectingActor)
{
	// if i've not already greeted and greet inclination
	return;
}

void Greet::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){

	}
}