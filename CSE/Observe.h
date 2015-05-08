#pragma once
#include "Action.h"

// player looks atthe environment around them. could be given extra functionality, such as noticing things so unlocking extra actions.
// or made to not take a moment. currently its pretty unsatisfying to use.
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

