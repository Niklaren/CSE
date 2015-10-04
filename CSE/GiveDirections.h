#pragma once
#include "ActionTargeted.h"

// give the correct directions (to grandmas lodge)
class GiveDirections :
	public ActionTargeted
{
public:
	GiveDirections(Actor* subject_, Actor* object_, int moments_);
	GiveDirections();
	~GiveDirections();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	virtual void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*);
	virtual double NPC_CalculateInclination();
};