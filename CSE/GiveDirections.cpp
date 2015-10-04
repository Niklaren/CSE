#include "stdafx.h"
//#include "GiveDirections.h"
#include "Actor.h"
#include "NPC_Actor.h"


GiveDirections::GiveDirections(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

GiveDirections::GiveDirections()
{
	Init();
}

GiveDirections::~GiveDirections()
{
}

void GiveDirections::Init()
{
	verb = "GiveDirections";

	//effect
	WorldStateProperty effect1, effect2, effect3;
	effect1.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_AskDirections);
	effects.push_back(effect1);
	//effect2.SetWSProperty(WSP_GiveDirections, WST_bool, true);
	//effects.push_back(effect2);

	// conditions
	WorldStateProperty condition1;
	// no condition

}

std::string GiveDirections::GetSentence()
{
	if (subject->GetName() == "Wolf")
		return "Well, there's a lodge back down the path if you turn back.";
	else
		return "Head out down that path, its not too far";
}

bool GiveDirections::GetUsable()
{
	return true;
}

// with the new knowledge of direction the asker can immediately travel to the lodge.
void GiveDirections::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	ws->WSProperties[WSP_ReactToWorldStateEvent].SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_AskDirections);
	
	if (object->GetName() == "You" && subject->GetName() == "Lumberjack")
		object->AddAction("Go To Lodge");
}

void GiveDirections::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){

	}
	if (affectingActor == subject){
		affectingActor->Change_Conscientious(0.05); //become slightly more conscientious
	}
}
// basically the opposite of give false direction. will help if conscientious or likes asker. weighted by how agreeable they are.
double GiveDirections::NPC_CalculateInclination() //openness(sociability) could be considered a factor.
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Conscientious();
	double b = static_cast<NPC_Actor*>(subject)->Get_Agreeable();
	double w = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID()); // I think they're mean = weight on conscientious.
	double result = Blend(a, b, w);												  // I think they're nice = weight on my niceness
	return result;
}