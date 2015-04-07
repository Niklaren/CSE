#pragma once
#include "Action.h"
class FetchWater :
	public Action
{
public:
	FetchWater(Actor* subject_, Stage* location, int moments_);
	FetchWater();
	~FetchWater();

	void Init();

	std::string GetSentence();

	virtual void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};