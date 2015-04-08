#pragma once
#include "Action.h"
class Observe :
	public Action
{
public:
	Observe(Actor* subject_, int moments_);
	~Observe();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
};

