#include "stdafx.h"
//#include "Answer.h"
#include "Actor.h"
#include "NPC_Actor.h"


Answer::Answer(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

Answer::Answer()
{
	Init();
}

Answer::~Answer()
{
}

void Answer::Init()
{
	verb = "Answer";

	if (object->GetHistory()->EventJustHappened("QueryIdentity"))
		query = "identity";
	if (object->GetHistory()->EventJustHappened("QueryPurpose"))
		query = "purpose";
	if (object->GetHistory()->EventJustHappened("QueryBasket"))
		query = "basket";
}

std::string Answer::GetSentence()
{
	if (query == "identity")
		return "I'm Red.";
	if (query == "purpose")
		return "I'm Going to Grandma's.";
	if (query == "basket")
		return "It's the Lunch I made.";
	return "answer";
}

bool Answer::GetUsable()
{
	if ((query == "identity") || (query == "purpose") || (query == "basket"))
		return true;
	return false;
}

void Answer::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	subject->RemoveAction("Answer");

	if (query == "identity")
		;
	if (query == "purpose")
		ws->WSProperties[WSP_WolfKnowsGrandma].SetValue(true);
	if (query == "basket")
		;
}

void Answer::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}