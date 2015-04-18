#include "stdafx.h"
//#include "Apologize.h"
#include "Actor.h"
#include "NPC_Actor.h"


Apologize::Apologize(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

Apologize::Apologize()
{
	Init();
}

Apologize::~Apologize()
{
}

void Apologize::Init()
{
	verb = "Apologize";

}

std::string Apologize::GetSentence()
{
	return "I'm so sorry. I couldn't deliver your Food";
}


void Apologize::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	ws->WSProperties[WSP_DeliveryFailed].SetValue(true);

	subject->RemoveAction("Apologize");
}

void Apologize::EmotionalReaction(NPC_Actor* affectingActor)
{

	if (affectingActor == object){
		Goal g;
		g.SetRelevance(0.7f);
		g.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Apologize);
		affectingActor->AddGoal(g);

		affectingActor->Change_pConscientious(-0.3, object->GetID());
		affectingActor->Change_pAgreeable(-0.1, object->GetID());
		affectingActor->Change_Agreeable(-0.1);
		affectingActor->Change_Angry(0.1);
	}
	if (affectingActor == subject){

	}
}

float Apologize::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double b = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
	double w = static_cast<NPC_Actor*>(subject)->Get_Happy();
	double result = Blend(a, b, w);
	return float(result);
}