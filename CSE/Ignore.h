#pragma once
#include "ActionTargeted.h"

class Ignore :
	public ActionTargeted
{
protected:

public:
	Ignore(Actor* subject_, Actor* object_, int moments_);
	~Ignore();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
};

