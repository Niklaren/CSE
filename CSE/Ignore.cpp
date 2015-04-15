#include "stdafx.h"
#include "Ignore.h"
#include "Actor.h"
#include "NPC_Actor.h"


Ignore::Ignore(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	verb = "Ignore";
}


Ignore::~Ignore()
{
}

std::string Ignore::GetSentence()
{
	return "you do your best to ignore the wolf.";
}

void Ignore::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	subject->RemoveAction("Ignore");
}

void Ignore::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
	else if (affectingActor == subject){
		affectingActor->Change_Happy(-0.1);
		affectingActor->Change_Angry(0.2);
		affectingActor->Change_pAgreeable(-0.1, subject->GetID());
	}
	affectingActor->Change_pAgreeable(-0.1, subject->GetID());
	affectingActor->Change_pExtraverted(-0.2, subject->GetID());

}
