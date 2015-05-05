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
		return "You tell the wolf your name.";
	if (query == "purpose")
		return "You explain that your grandma is ill and you must deliver her food.";
	if (query == "basket")
		return "You tell the wolf the basket you carry contains food.";
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
	if (affectingActor == object){
		if (query == "purpose"){
			Goal g;
			g.SetRelevance(0.86f);
			g.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_WolfKnowsGrandma);
			affectingActor->AddGoal(g);
		}

		affectingActor->Change_pAgreeable(0.2, subject->GetID());
		affectingActor->Change_pExtraverted(0.2, subject->GetID());
	}
}