#include "stdafx.h"
//#include "BeginLRR.h"

#include "Player_Actor.h"
#include "NPC_Actor.h"


BeginLRR::BeginLRR(Actor* subject_, Player_Actor* r, NPC_Actor* w, NPC_Actor* l, NPC_Actor* g, int moments_)
	: Action(subject_,moments_)
{
	subject = subject_;
	verb = "Begin";
	
	locationOccured = r->GetLocation();

	red = r;
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
	
	//YOU
	red->AddAction("Observe");
	red->AddAction("Eat Some Food");
	red->AddAction("Walk Path");
	red->AddAction("Stray Off Path");
	red->AddAction("Go Home");
	//red->AddAction("Give Food");

	// WOLF
	//wolf->AddAction("OK");
	//wolf->AddAction("Travel");
	//wolf->AddAction("Eat");

	wolf->AddAction("WolfGreetRed", red);
	wolf->AddAction("GiveDirections", red);
	wolf->AddAction("GiveWrongDirections", red);
	wolf->AddAction("WolfKnowsGrandmaReaction");
	wolf->AddAction("QueryIdentity", red);
	wolf->AddAction("QueryPurpose", red);
	wolf->AddAction("QueryBasket", red);

	wolf->AddAction("WolfEat", red);
	wolf->AddAction("WolfEat", grandma);
	wolf->AddAction("WolfEatLunch");
	wolf->AddAction("SuggestFlowers", red);
	wolf->AddAction("RequestEntry", grandma);

	// GRANNY
	grandma->AddAction("OpenDoor");
	grandma->AddAction("Greet", red);
	grandma->AddAction("Hug", red);
	grandma->AddAction("Kiss", red);
	grandma->AddAction("Thank", red);

	grandma->AddAction("Reprimand", red);
	grandma->AddAction("Forgive", red);

	// LUMBERJACK
	//lumberjack->AddAction("OK");

	lumberjack->AddAction("ChopLog", cabin);
	lumberjack->AddAction("LogOnstump", cabin);
	lumberjack->AddAction("Grablog", cabin);
	//lumberjack->AddAction("Travel");
	lumberjack->AddAction("Greet", red);
	lumberjack->AddAction("GiveDirections", red);
	lumberjack->AddAction("GiveWrongDirections", red);
	lumberjack->AddAction("AgreeEscort", red);
	lumberjack->AddAction("RefuseEscort", red);

}

void BeginLRR::EmotionalReaction(NPC_Actor* affectingActor)
{

}

std::string BeginLRR::GetSentence()
{
	return "Unfortunately your Grandmother fell ill recently. You prepared a lunch for you both to share.";
}