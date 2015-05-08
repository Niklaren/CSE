#pragma once
#include "ActionTargeted.h"

// ignore a question. rude, and so reflects poorly on the character.
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

