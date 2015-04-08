#pragma once
#include "Action.h"

class ChopLog :
	public Action
{
public:
	ChopLog(Actor* subject_, Stage* location, int moments_);
	ChopLog();
	~ChopLog();

	void Init();

	std::string GetSentence();

	virtual void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};