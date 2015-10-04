#pragma once
#include "ActionTargeted.h"

// request entryto the lodge.
class RequestEntry :
	public ActionTargeted
{
public:
	RequestEntry(Actor* subject_, Actor* object_, int moments_);
	RequestEntry();
	~RequestEntry();

	void Init();

	std::string GetSentence();

	virtual void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*);
	virtual double NPC_CalculateInclination();
};

