#pragma once
#include "ActionTargeted.h"

class Hug :
	public ActionTargeted
{
public:
	Hug(Actor* subject_, Actor* object_, int moments_);
	Hug();
	~Hug();
	void Init();

	std::string GetSentence();
	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};
