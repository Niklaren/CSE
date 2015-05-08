#pragma once
#include "ActionTargeted.h"

// can give flowers to somebody to increase their perception of you.
class GiveFlowers :
	public ActionTargeted
{
protected:
	std::string query;
public:
	GiveFlowers(Actor* subject_, Actor* object_, int moments_);
	GiveFlowers();
	~GiveFlowers();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
};