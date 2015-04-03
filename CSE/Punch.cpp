#include "stdafx.h"

#include <iostream>

//#include "Punch.h"
#include "Actor.h"
#include "NPC_Actor.h"


Punch::Punch(Actor* subject_, Actor* object_, int moments_=1)
	: Action(moments_)
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
	effect1.SetWSProperty(WSP_Punched, WST_bool, true);
	effects.push_back(effect1);



	// conditions
	// same location as target??
	WorldStateProperty condition1;
	condition1.SetWSProperty(WSP_Insulted, WST_bool, true);
	conditions.push_back(condition1);
}

void Punch::ExecuteConsequences(WorldState* ws)
{


}

void Punch::NPC_CalculateInclination(NPC_Actor* affectingActor)
{
	/*if (affectingActor == object){
		double punch_inclination = -affectingActor->Get_Agreeable();//Blend(-affectingActor->Get_Agreeable())
		double apologize_inclination = affectingActor->Get_Agreeable();
		if (punch_inclination > 0)
			affectingActor->Plan("Punch", 1, subject); // return the punch to the puncher
		if (apologize_inclination > 0)
			affectingActor->Plan("Apologize", 1, subject);
	}
	return;*/
}

void Punch::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_Agreeable(-0.15);
		double angerChange = affectingActor->EmotionalCoefficient() * 0.15;
		affectingActor->Change_Angry(angerChange);
	}
}