#include "stdafx.h"

#include <iostream>

//#include "Punch.h"
#include "Actor.h"
#include "NPC_Actor.h"


Punch::Punch(Actor* subject_, Actor* object_, int moments_=1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

	subject = subject_;
	object = object_;
}

Punch::Punch()
{
	Init();
}

Punch::~Punch()
{

}

void Punch::Init()
{
	verb = "Punch";

	// effects
	WorldStateProperty effect1, effect2;
	effect1.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Apologize);
	effects.push_back(effect1);

	// conditions
	// same location as target??

}

void Punch::ExecuteConsequences(WorldState* ws)
{


}

float Punch::NPC_CalculateInclination()
{
	/*if (affectingActor == object){
		double punch_inclination = -affectingActor->Get_Agreeable();//Blend(-affectingActor->Get_Agreeable())
		double apologize_inclination = affectingActor->Get_Agreeable();
		if (punch_inclination > 0)
			affectingActor->Plan("Punch", 1, subject); // return the punch to the puncher
		if (apologize_inclination > 0)
			affectingActor->Plan("Apologize", 1, subject);
	}*/
	return 0;
}

void Punch::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_Agreeable(-0.15);
		double angerChange = affectingActor->EmotionalCoefficient() * 0.15;
		affectingActor->Change_Angry(angerChange);
	}
}

std::string Punch::GetSentence()
{
	if (subject->GetName() == "You"){
		return "you make a joke about it. Ash laughs.";
	}
	return subject->GetName() + " laughs it off. all good.";
}