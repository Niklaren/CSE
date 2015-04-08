#pragma once
#include "Action.h"
class PickFlowers :
	public Action
{
public:
	PickFlowers(Actor* subject_, int moments_);
	~PickFlowers();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
};

