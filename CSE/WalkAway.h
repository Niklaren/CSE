#pragma once
#include "Action.h"
class WalkAway :
	public Action
{
public:
	WalkAway(Actor* subject_, int moments_);
	~WalkAway();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
};

