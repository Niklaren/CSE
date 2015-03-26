#include "stdafx.h"
//#include "Hug.h"
#include "Actor.h"
#include "NPC_Actor.h"


Hug::Hug(Actor* subject_, Actor* object_, int moments_ = 1)
	: Action(moments_)
{
	subject = subject_;
	verb = "hugs";
	object = object_;
}


Hug::~Hug()
{
}

void Hug::NPC_CalculateInclination(NPC_Actor* affectingActor)
{
	if ((affectingActor == object) && (subject->GetName() != "protagonist")){
		//affectingActor->Plan("Apologize", subject);
	}
	return;
}

void Hug::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_Agreeable(0.5);
		affectingActor->Change_pAgreeable(0.2);
		double happyChange = affectingActor->EmotionalCoefficient() * 0.1;
		affectingActor->Change_Happy(happyChange);
	}
}