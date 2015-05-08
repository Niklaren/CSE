#pragma once
#include "Action.h"

// flee from the dangerous wolf if he looks to attack you.
class Flee :
	public Action
{
private:
	Stage* fleeTo;

public:
	Flee(Actor* subject_, Stage* s, int moments_);
	~Flee();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
};
