#include "stdafx.h"
//#include "Intervene.h"
#include "Actor.h"
#include "NPC_Actor.h"


Intervene::Intervene(Actor* subject_, NPC_Actor* a1_, NPC_Actor* a2_, int moments_ = 1)
	: Action(moments_)
{
	subject = subject_;
	verb = "Intervene";
	a1 = a1_;
	a2 = a2_;
}


Intervene::~Intervene()
{
}

void Intervene::React()
{
	a1->React();
	a2->React();
}

void Intervene::ExecuteConsequences(WorldState* ws)
{
}

void Intervene::NPC_CalculateInclination(NPC_Actor* affectingActor)
{
	return;
}

void Intervene::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == a1 || affectingActor == a2)
	{
		affectingActor->Change_Agreeable(0.5);
		double happyChange = affectingActor->EmotionalCoefficient() * 0.2;
		affectingActor->Change_Happy(happyChange);
	}
}