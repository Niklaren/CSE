#include "stdafx.h"

#include <iostream>

//#include "Punch.h"
#include "Actor.h"
#include "NPC_Actor.h"


Punch::Punch(Actor* subject_, Actor* object_, int moments_=1)
	: Action(moments_)
{
	subject = subject_;
	verb = "punches";
	object = object_;
}


Punch::~Punch()
{

}

void Punch::NPC_CalculateInclination(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		double punch_inclination = -affectingActor->Get_Agreeable();//Blend(-affectingActor->Get_Agreeable())
		double apologize_inclination = affectingActor->Get_Agreeable();
		if (punch_inclination > 0)
			affectingActor->Plan("Punch", subject); // return the punch to the puncher
		if (apologize_inclination > 0)
			affectingActor->Plan("Apologize", subject);
	}
	return;
}

void Punch::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_Agreeable(-0.15);
		double angerChange = affectingActor->EmotionalCoefficient() * 0.15;
		affectingActor->Change_Angry(angerChange);
	}
}