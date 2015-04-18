#include "stdafx.h"
//#include "RequestEntry.h"
#include "Actor.h"
#include "NPC_Actor.h"


RequestEntry::RequestEntry(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();
}

RequestEntry::RequestEntry()
{
	Init();
}

RequestEntry::~RequestEntry()
{

}

void RequestEntry::Init()
{
	verb = "RequestEntry";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_DoorOpen, WST_bool, true);
	effects.push_back(effect1);

	// conditions
	WorldStateProperty condition1, condition2;
	condition1.SetWSProperty(WSP_WolfKnowsGrandma, WST_bool, true);
	conditions.push_back(condition1);
	condition2.SetWSProperty(WSP_RedDistracted, WST_bool, true);
	conditions.push_back(condition2);
}

std::string RequestEntry::GetSentence()
{
	return subject->GetName() + ": May I come in?";
}

void RequestEntry::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	subject->RemoveAction("Request Entry");
	subject->RemoveAction("Knock Door");
}

void RequestEntry::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
	else if (affectingActor == object){
		Goal g(0.7f, "openDoor");
		g.SetWSProperty(WSP_DoorOpen, WST_bool, true);
		affectingActor->AddGoal(g);
	}
}

float RequestEntry::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_Open();
	double b = static_cast<NPC_Actor*>(subject)->Get_Conscientious();
	// w = static_cast<NPC_Actor*>(subject)->
	double result = Blend(a, b, 0) + 0.15;
	return float(result);
}
