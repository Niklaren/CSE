#include "stdafx.h"
//#include "OpenDoor.h"
#include "Actor.h"
#include "NPC_Actor.h"

OpenDoor::OpenDoor(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
	Init();
}

OpenDoor::OpenDoor()
{
	Init();
}

OpenDoor::~OpenDoor()
{
}

void OpenDoor::Init()
{
	verb = "OpenDoor";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_DoorOpen, WST_bool, true);
	effects.push_back(effect1);

	// conditions
	WorldStateProperty condition1, condition2;

}

std::string OpenDoor::GetSentence()
{
	return "Granny unlocks the door and opens it slowly.";
}

void OpenDoor::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	ws->WSProperties[WSP_DoorOpen].SetValue(true);

}

void OpenDoor::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}

//double OpenDoor::NPC_CalculateInclination()
//{
//	return 0;
//}