#pragma once
#include "Action.h"
class End :
	public Action
{
public:
	End(Actor* subject_, int moments_);
	~End();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
};

