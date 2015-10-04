#include "stdafx.h"
//#include "GiveWrongDirections.h"
#include "Actor.h"
#include "NPC_Actor.h"


GiveWrongDirections::GiveWrongDirections(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

}

GiveWrongDirections::GiveWrongDirections()
{
	Init();
}

GiveWrongDirections::~GiveWrongDirections()
{
}

void GiveWrongDirections::Init()
{
	verb = "GiveWrongDirections";

	//effect
	WorldStateProperty effect1, effect2; // can satisfy a goal of responding to askDirections, or specifically to give wrong directions.
	effect1.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_AskDirections);
	effects.push_back(effect1);
	effect2.SetWSProperty(WSP_WrongDirections, WST_bool, true);
	effects.push_back(effect2);

	// conditions
	WorldStateProperty condition1;
	// no preconditions

}

std::string GiveWrongDirections::GetSentence()
{
	if (subject->GetName() == "Wolf") // wolf will deliberately mislead you. others would just apologize for not knowing the way.
		return "If you keep going this way I'm sure you'll make it.";
	else
		return "I'm sorry I don't know the way"; // would this be better suited to apologize???
}

bool GiveWrongDirections::GetUsable()
{

	return true;
}

void GiveWrongDirections::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);
	ws->WSProperties[WSP_ReactToWorldStateEvent].SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_AskDirections);
	ws->WSProperties[WSP_WrongDirections].SetValue(true);
}

void GiveWrongDirections::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){

	}
	if (affectingActor == subject){
		affectingActor->Change_Conscientious(-0.05);
	}
}

// inclination based upon how they dislike the asker, how lazy they are. weighted by how nice they are.
double GiveWrongDirections::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
	double b = static_cast<NPC_Actor*>(subject)->Get_Conscientious();
	double w = static_cast<NPC_Actor*>(subject)->Get_Agreeable(); // nicer = bigger weight on conscientious. meaner = bigger weight on dislike.
	double result = Blend(-a, -b, w);
	return result;
}