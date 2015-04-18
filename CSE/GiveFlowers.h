#pragma once
#include "ActionTargeted.h"

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