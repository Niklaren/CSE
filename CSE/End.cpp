#include "stdafx.h"
//#include "End.h"
#include "Actor.h"
#include "NPC_Actor.h"


End::End(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
	verb = "End";
}


End::~End()
{
}

std::string End::GetSentence()
{
	return ending + "\nThe End.";
}

void End::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	if (ws->WSProperties[WSP_DeliveryFailed].bvalue)
		ending = "you were unable to deliver lunch to grandma.";

	if (ws->WSProperties[WSP_GrandmaEaten].bvalue)
		ending = "the wolf had 'lunch' at grandma's.";

	if (ws->WSProperties[WSP_RedEaten].bvalue)
		ending = "you were able to deliver lunch... to the wolf..";

	if (ws->WSProperties[WSP_RedHome].bvalue)
		ending = "you decided to scrap the whole thing and go home.";

	if (ws->WSProperties[WSP_LunchDelivered].bvalue == true){
		ending = "you successfully delivered lunch.";
	}
	
	ws->WriteToFile();
	subject->GetHistory()->WriteToFile();
}

void End::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}

