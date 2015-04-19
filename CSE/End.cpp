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
		ending.append("You were unable to deliver lunch to grandma. ");

	if (ws->WSProperties[WSP_Forgiven].bvalue)
		ending.append("Grandma forgave you. ");

	if (ws->WSProperties[WSP_Reprimanded].bvalue)
		ending.append("Grandma did not forgive you. ");

	if (ws->WSProperties[WSP_RedHome].bvalue)
		ending.append("You decided to scrap the whole thing and go home. ");

	if (ws->WSProperties[WSP_GrandmaEaten].bvalue)
		ending.append("The wolf ate grandma for lunch. ");

	if (ws->WSProperties[WSP_RedEaten].bvalue)
		ending.append("You were able to deliver lunch... to the wolf... ");

	if (ws->WSProperties[WSP_LunchDelivered].bvalue == true){
		ending.append("You successfully delivered lunch. ");
	}

	if (ws->WSProperties[WSP_WolfDead].bvalue == true){
		ending.append("The Lumberjack slew the wolf.");
	}
	
}

void End::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}

