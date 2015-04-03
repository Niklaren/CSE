#pragma once
#include "Action.h"
class CookBad :
	public Action
{
public:
	CookBad(Actor* subject_, int moments_);
	CookBad();
	~CookBad();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};