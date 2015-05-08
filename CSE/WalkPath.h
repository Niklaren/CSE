#pragma once
#include "ActionTargeted.h"

// walk down the path action from the first area.
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
};