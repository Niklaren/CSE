#pragma once
#include "ActionTargeted.h"
class SuggestFlowers :
	public ActionTargeted
{
public:
	SuggestFlowers(Actor* subject_, Actor* object_, int moments_);
	SuggestFlowers();
	~SuggestFlowers();

	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};

