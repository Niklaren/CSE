#pragma once
#include "Action.h"
class Prepare :
	public Action
{
public:
	Prepare(Actor* subject_, int moments_);
	Prepare();
	~Prepare();

	virtual std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*);
};

