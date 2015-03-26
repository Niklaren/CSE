#include "stdafx.h"
//#include "Insult.h"
#include "Actor.h"
#include "NPC_Actor.h"


Insult::Insult(Actor* subject_, Actor* object_, int moments_ = 1)
	: Action(moments_)
{
	subject = subject_;
	verb = "insults";
	object = object_;
}


Insult::~Insult()
{
}

void Insult::NPC_CalculateInclination(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		double punch_inclination = -affectingActor->Get_Agreeable();//Blend(-affectingActor->Get_Agreeable())
		double insult_inclination = -affectingActor->Get_Agreeable();//Blend(-affectingActor->Get_Agreeable())
		if (punch_inclination > 0.5)
			affectingActor->Plan("Punch", subject);
		else if (insult_inclination > 0.0)
			affectingActor->Plan("Insult", subject);

	}
	return;
}

void Insult::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		//if subject = protagonist
		//affectingActor->Change_ppAgreeable(-0.1);
		//else if subject = B
		//affectingActor->Change_pAgreeable(-0.1);

		//affectingActor->Change_pAgreeable(subject, -0.1)

		affectingActor->Change_Agreeable(-0.15);
		double angerChange = affectingActor->EmotionalCoefficient() * 0.15;
		affectingActor->Change_Angry(angerChange);
	}
}
