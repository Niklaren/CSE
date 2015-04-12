#pragma once
#include "ActionTargeted.h"
class RequestEntry :
	public ActionTargeted
{
public:
	RequestEntry(Actor* subject_, Actor* object_, int moments_);
	RequestEntry();
	~RequestEntry();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};

