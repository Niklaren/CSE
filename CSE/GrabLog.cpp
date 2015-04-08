#include "stdafx.h"
//#include "GrabLog.h"
#include "Actor.h"
#include "NPC_Actor.h"

GrabLog::GrabLog(Actor* subject_, Stage* l, int moments_ = 1)
	: Action(subject_, moments_)
{
	locationOccured = l;
	Init();
}

GrabLog::GrabLog()
{
	Init();
}

GrabLog::~GrabLog()
{
}

void GrabLog::Init()
{
	verb = "GrabLog";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_JackHasLumber, WST_bool, true);
	effects.push_back(effect1);

	// conditions
	WorldStateProperty condition1, condition2;
	condition1.SetWSProperty(WSP_Location, WST_variable);
	conditions.push_back(condition1);

}

std::string GrabLog::GetSentence()
{
	return subject->GetName() + " grabs a log from the pile.";
}

void GrabLog::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	ws->WSProperties[WSP_JackHasLumber].SetWSProperty(WSP_JackHasLumber, WST_bool, true);

}

void GrabLog::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}

float GrabLog::NPC_CalculateInclination()
{
	return 0;
}