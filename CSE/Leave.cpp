#include "stdafx.h"
////#include "Leave.h"
//#include "Actor.h"
//#include "NPC_Actor.h"
//
//
//Leave::Leave(Actor* subject_, int moments_)
//	: Action(subject_, moments_)
//{
//	Init();
//}
//
//Leave::Leave()
//{
//	Init();
//}
//
//Leave::~Leave()
//{
//
//}
//
//void Leave::Init()
//{
//	verb = "Leave";
//}
//
//std::string Leave::GetSentence()
//{
//	return subject->GetName() + " leaves the area.";
//}
//
//void Leave::ExecuteConsequences(WorldState* ws)
//{
//	Action::ExecuteConsequences(ws);
//
//	//subject->removeactions location actions
//	locationOccured->RemoveLocationActions(subject);
//}
//
//void Leave::EmotionalReaction(NPC_Actor* affectingActor)
//{
//
//}
//
//double Leave::NPC_CalculateInclination()
//{
//	return 0;
//}
//
//bool Leave::ReadyToExecute()
//{
//	if (momentsFromExecution == 0)
//	{
//		return true;
//	}
//
//	return false;
//}