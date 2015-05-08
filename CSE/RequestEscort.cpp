#include "stdafx.h"
//#include "RequestEscort.h"
#include "Actor.h"
#include "NPC_Actor.h"


RequestEscort::RequestEscort(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

RequestEscort::RequestEscort()
{
	Init();
}

RequestEscort::~RequestEscort()
{
}

void RequestEscort::Init()
{
	verb = "RequestEscort";

}

std::string RequestEscort::GetSentence()
{
	return "You explain you run in with the wolf, and ask if the lumberjack would be willing to accompany you back to Grandma's house.";
}

void RequestEscort::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	subject->RemoveAction("Request Escort");

}

// gives the target a goal of responding to the request.
void RequestEscort::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_pExtraverted(-0.1, subject->GetID());
		affectingActor->Change_pOpen(-0.1, subject->GetID());

		Goal g;
		g.SetRelevance(0.85f);
		g.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_RequestEscort);
		affectingActor->AddGoal(g);
	}
}