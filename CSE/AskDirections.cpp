#include "stdafx.h"
//#include "AskDirections.h"
#include "Actor.h"
#include "NPC_Actor.h"


AskDirections::AskDirections(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

AskDirections::AskDirections()
{
	Init();
}

AskDirections::~AskDirections()
{
}

void AskDirections::Init()
{
	verb = "AskDirections";

}

std::string AskDirections::GetSentence()
{
	return "You ask for the way to grandma's house";
}

bool AskDirections::GetUsable()
{

	return true;
}

void AskDirections::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	subject->RemoveAction("Ask Directions");
	ws->WSProperties[WSP_WolfKnowsGrandma].SetValue(true);
}

void AskDirections::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_Angry(0.05);
		affectingActor->Change_pExtraverted(0.1, subject->GetID());
		affectingActor->Change_pConscientious(-0.1, subject->GetID());

		Goal g;
		g.SetRelevance(0.85f);
		g.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_AskDirections);
		affectingActor->AddGoal(g);
	}
	if (affectingActor == subject){

	}
}