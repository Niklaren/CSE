#pragma once
#include "ActionTargeted.h"

class Punch :
	public ActionTargeted
{
public:
	Punch();
	Punch(Actor* subject_, Actor* object_, int moments_);
	~Punch();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	float NPC_CalculateInclination();
	void EmotionalReaction(NPC_Actor*);
};

