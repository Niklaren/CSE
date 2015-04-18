#pragma once
#include "Action.h"

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
