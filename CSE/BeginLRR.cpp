#include "stdafx.h"
//#include "BeginLRR.h"
#include "Actor.h"
#include "NPC_Actor.h"


BeginLRR::BeginLRR(Actor* subject_, Actor* p, Actor* w, Actor* l, Actor* g, int moments_)
	: Action(subject_,moments_)
{
	subject = subject_;
	verb = "Begin";
	
	locationOccured = p->GetLocation();

	player = p;
	wolf = w;
	lumberjack = l;
	grandma = g;
}


BeginLRR::~BeginLRR()
{
}

void BeginLRR::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	player->AddAction("Observe");
	player->AddAction("Eat Some Food");
	player->AddAction("Walk Path");
	player->AddAction("Stray Off Path");
	player->AddAction("Go Home");
	//player->AddAction("Give Food");


}

void BeginLRR::EmotionalReaction(NPC_Actor* affectingActor)
{

}

std::string BeginLRR::GetSentence()
{
	return "Unfortunately your Grandmother fell ill recently. You prepared a lunch for you both to share.";
}