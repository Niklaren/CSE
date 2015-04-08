#include "stdafx.h"
//#include "LogOnStump.h"
#include "Actor.h"
#include "NPC_Actor.h"

LogOnStump::LogOnStump(Actor* subject_, Stage* l, int moments_ = 1)
	: Action(subject_, moments_)
{
	locationOccured = l;
	Init();
}

LogOnStump::LogOnStump()
{
	Init();
}

LogOnStump::~LogOnStump()
{
}

void LogOnStump::Init()
{
	verb = "LogOnStump";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_LumberOnStump, WST_bool, true);
	effects.push_back(effect1);

	// conditions
	WorldStateProperty condition1, condition2;
	condition1.SetWSProperty(WSP_Location, WST_variable);
	conditions.push_back(condition1);
	condition2.SetWSProperty(WSP_JackHasLumber, WST_bool, true);
	conditions.push_back(condition2);

}

std::string LogOnStump::GetSentence()
{
	return subject->GetName() + " places the log atop the wide tree stump.";
}

void LogOnStump::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	ws->WSProperties[WSP_JackHasLumber].SetWSProperty(WSP_JackHasLumber, WST_bool, false);
	ws->WSProperties[WSP_LumberOnStump].SetWSProperty(WSP_LumberOnStump, WST_bool, true);

}

void LogOnStump::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}

float LogOnStump::NPC_CalculateInclination()
{
	return 0;
}