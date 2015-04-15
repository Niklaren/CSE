#include "stdafx.h"
//#include "Greet.h"
#include "Actor.h"
#include "NPC_Actor.h"


Greet::Greet(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

Greet::Greet()
{
	Init();
}

Greet::~Greet()
{
}

void Greet::Init()
{
	verb = "Greet";

	//effect
	WorldStateProperty effect1, effect2, effect3;
	effect1.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Greet);
	effects.push_back(effect1);
	effect2.SetWSProperty(WSP_Greeting, WST_bool, true);
	effects.push_back(effect2);

	// conditions
	WorldStateProperty condition1;
	//condition1.SetWSProperty(WSP_Location, WST_variable);
	//conditions.push_back(condition1);

}

std::string Greet::GetSentence()
{
	if (subject->GetName() == "You"){
		if (object->GetName() == "Wolf")
			return "You acknowledge the wolf.";
		else if (object->GetName() == "Grandma")
			return "Hello grandma.";
		else if (object->GetName() == "Lumberjack")
			return "You attract the lumberjack's attention.";
	}
	return "Greetings";
}

bool Greet::GetUsable()
{
	if (!(subject->GetHistory()->HaventDoneEventBefore(subject, verb))) // if we've done it before
		return false;
	return true;
}

void Greet::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	subject->RemoveAction("Greet");
}

void Greet::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		//Goal g;
		//g.SetRelevance(0.7f);
		//g.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Greet);
		//affectingActor->AddGoal(g);
		affectingActor->Change_pAgreeable(0.15, subject->GetID());
		affectingActor->Change_Extraverted(0.01);
	}
	if (affectingActor == subject){
		
	}
}

float Greet::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double b = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
	double w = static_cast<NPC_Actor*>(subject)->Get_Happy();
	double result = Blend(a, b, w);
	return float(result);
}