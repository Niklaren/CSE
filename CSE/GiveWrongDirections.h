#pragma once
#include "ActionTargeted.h"

// give incorrect directions in response to a request directions
class GiveWrongDirections :
	public ActionTargeted
{
public:
	GiveWrongDirections(Actor* subject_, Actor* object_, int moments_);
	GiveWrongDirections();
	~GiveWrongDirections();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	virtual void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*);
	virtual float NPC_CalculateInclination();
};