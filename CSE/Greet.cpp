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
	condition1.SetWSProperty(WSP_Location, WST_variable);
	conditions.push_back(condition1);

}

std::string Greet::GetSentence()
{
	if (subject->GetName() == "You"){
		if (object->GetName() == "Ash")
			return "Your old pal Ash, it's been awhile. Hi!";
		else if (object->GetName() == "Brooke")
			return "The friend Ash told you About, Brooke.";
	}
	else if (subject->GetName() == "Ash"){
		return "Ash greets you warmly.";
	}
	else{
		return "Brooke says hi. nice to meet you.";
	}
	return "greetings";
}

bool Greet::GetUsable()
{
	if (!(subject->GetHistory()->HaventDoneEventBefore(subject, verb))) // if we've done it before
			return false;
	if (subject->GetHistory()->TimeSinceStart() > 5) // if we've moved passed greeting stage
		return false;
	return true;
}

void Greet::ExecuteConsequences(WorldState* ws)
{
	
}

void Greet::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		Goal g;
		g.SetRelevance(0.7f);
		g.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Greet);
		affectingActor->AddGoal(g);
	}
	if (affectingActor == subject){
		
	}
}

float Greet::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double b = static_cast<NPC_Actor*>(subject)->Get_pPAgreeable();
	double w = static_cast<NPC_Actor*>(subject)->Get_Happy();
	double result = Blend(a, b, w);
	return float(result);
}