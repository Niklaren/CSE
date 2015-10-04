#pragma once
#include "Action.h"

// lumberjack will constantly chop wood.
class LogOnStump :
	public Action
{
public:
	LogOnStump(Actor* subject_, Stage* location, int moments_);
	LogOnStump();
	~LogOnStump();

	void Init();

	std::string GetSentence();

	virtual void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*);
	//double NPC_CalculateInclination();
};