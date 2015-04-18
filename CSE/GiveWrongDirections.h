#pragma once
#include "ActionTargeted.h"

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

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};