#pragma once
#include "ActionTargeted.h"

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

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};