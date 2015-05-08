#include "stdafx.h"
//#include "Reprimand.h"
#include "Actor.h"
#include "NPC_Actor.h"


Reprimand::Reprimand(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

Reprimand::Reprimand()
{
	Init();
}

Reprimand::~Reprimand()
{
}

void Reprimand::Init()
{
	verb = "Reprimand";

	//effect
	WorldStateProperty effect1, effect2, effect3;
	effect2.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Apologize);
	effects.push_back(effect2);

	// conditions
	WorldStateProperty condition1;
	//condition1.SetWSProperty(WSP_Location, WST_variable);
	//conditions.push_back(condition1);

}

std::string Reprimand::GetSentence()
{
	return "Grandma lectures you for losing the food.";
}

bool Reprimand::GetUsable()
{
	if (!(subject->GetHistory()->HaventDoneEventBefore(subject, verb))) // if we've done it before
		return false;
	return true;
}

void Reprimand::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	subject->RemoveAction("Reprimand");
	subject->RemoveAction("Forgive");
	ws->WSProperties[WSP_ReactToWorldStateEvent].SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Apologize);
	ws->WSProperties[WSP_Reprimanded].SetValue(true);
}

void Reprimand::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_Angry(0.1);
	}
	if (affectingActor == subject){

	}
}

// inclination based off how mean she is and how lazy she perceives you to be. 
float Reprimand::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double b = static_cast<NPC_Actor*>(subject)->Get_pConscientious(object->GetID());
	double w = static_cast<NPC_Actor*>(subject)->Get_Conscientious();	// weighting: the harderworking she is; the greater importance placed on you conscientiousness
	double result = Blend(-a, -b, w);
	return float(result);
}