#include "stdafx.h"
//#include "Intimidate.h"
#include "Actor.h"
#include "NPC_Actor.h"


Intimidate::Intimidate(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

Intimidate::Intimidate()
{
	Init();
}

Intimidate::~Intimidate()
{
}

void Intimidate::Init()
{
	verb = "Intimidate";

	//effect
	WorldStateProperty effect1, effect2, effect3;
	effect1.SetWSProperty(WSP_RedPanicked, WST_bool, true);
	effects.push_back(effect1);

	// conditions
	WorldStateProperty condition1;
	//condition1.SetWSProperty(WSP_WolfGreetRed, WST_bool, true);
	//conditions.push_back(condition1);

}

std::string Intimidate::GetSentence()
{
	return "The wolf rushes towards you and bares his teeth.";
}

bool Intimidate::GetUsable()
{
	if (!(subject->GetHistory()->HaventDoneEventBefore(subject, verb))) // if we've done it before
		return false;
	return true;
}

void Intimidate::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	ws->WSProperties[WSP_RedPanicked].SetValue(true);

	object->AddAction("Flee");
}

void Intimidate::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_pAgreeable(-0.1,subject->GetID());
	}
	if (affectingActor == subject){
		affectingActor->Change_Angry(0.1);
	}
}

// inclination based on how much the subject dislikes the target. and how disagreeable they are.
// higher anger means that what they think of the target becomes more important.
double Intimidate::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double b = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
	double w = static_cast<NPC_Actor*>(subject)->Get_Angry();
	double result = Blend(-a, -b, w);
	return result;
}