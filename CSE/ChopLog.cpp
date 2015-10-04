#include "stdafx.h"
//#include "ChopLog.h"
#include "Actor.h"
#include "NPC_Actor.h"

ChopLog::ChopLog(Actor* subject_, Stage* l, int moments_ = 1)
	: Action(subject_, moments_)
{
	locationOccured = l;
	Init();
}

ChopLog::ChopLog()
{
	Init();
}

ChopLog::~ChopLog()
{
}

void ChopLog::Init()
{
	verb = "ChopLog";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_LumberChopped, WST_int, 1); // switch this to a +1
	effects.push_back(effect1);

	// conditions
	WorldStateProperty condition1, condition2;
	//condition1.SetWSProperty(WSP_Location, WST_variable);
	//conditions.push_back(condition1);
	condition2.SetWSProperty(WSP_LumberOnStump, WST_bool, true);
	conditions.push_back(condition2);

}

std::string ChopLog::GetSentence()
{
	return subject->GetName() + " chops the log and tosses the pieces on the pile";
}

void ChopLog::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	ws->WSProperties[WSP_LumberOnStump].SetWSProperty(WSP_LumberOnStump, WST_bool, false);

}

void ChopLog::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == subject){

	}
}

//double ChopLog::NPC_CalculateInclination()
//{
//	return 0;
//}