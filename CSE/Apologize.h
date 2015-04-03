#pragma once
#include "ActionTargeted.h"

class Apologize :
	public ActionTargeted
{
public:
	Apologize(Actor* subject_, Actor* object_, int moments_);
	Apologize();
	~Apologize();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};