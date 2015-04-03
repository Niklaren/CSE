#pragma once
#include "Action.h"
class FetchWater :
	public Action
{
public:
	FetchWater(Actor* subject_, int moments_);
	FetchWater();
	~FetchWater();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};