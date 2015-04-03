#include "stdafx.h"
//#include "Apologize.h"
#include "Actor.h"
#include "NPC_Actor.h"


Apologize::Apologize(Actor* subject_, Actor* object_, int moments_ = 1)
	: Action(moments_)
{
	subject = subject_;
	verb = "Apologize";
	object = object_;
}


Apologize::~Apologize()
{
}

void Apologize::ExecuteConsequences(WorldState* ws)
{
}

void Apologize::NPC_CalculateInclination(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		//double Apolo_inclination = -affectingActor->Get_Agreeable();//Blend(-affectingActor->Get_Agreeable())
		//double hug_inclination = affectingActor->Get_Agreeable();//Blend(-affectingActor->Get_Agreeable())
		//else if (hug_inclination > 0.0)
		affectingActor->Plan("Hug", 1, subject);

	}
	return;
}

void Apologize::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_Agreeable(0.1);
		double angerChange = affectingActor->EmotionalCoefficient() * -0.15;
		affectingActor->Change_Angry(angerChange);
	}
}