#pragma once
#include "ActionTargeted.h"

class WalkPath :
	public Action
{
public:
	WalkPath(Actor* subject_, int moments_);
	WalkPath();
	~WalkPath();

	std::string GetSentence();

	virtual bool GetUsable();

	virtual void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*);
};