#pragma once
#include "Action.h"
class FetchWood :
	public Action
{
public:
	FetchWood(Actor* subject_, int moments_);
	FetchWood();
	~FetchWood();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};