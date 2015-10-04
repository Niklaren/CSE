#pragma once
#include "ActionTargeted.h"

// suggest red pick flowers to buy time to eat grandma
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
	double NPC_CalculateInclination();
};

