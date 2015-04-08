#pragma once
#include "Action.h"

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
	float NPC_CalculateInclination();
};