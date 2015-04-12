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

	Goal g(0.5f);
	g.SetWSProperty(WSP_LumberChopped, WST_int, 1);
	static_cast<NPC_Actor*>(lumberjack)->AddGoal(g);

}

void BeginLRR::EmotionalReaction(NPC_Actor* affectingActor)
{

}

std::string BeginLRR::GetSentence()
{
	return "Unfortunately your Grandmother fell ill recently. \nYou prepared a lunch for you both to share.";
}