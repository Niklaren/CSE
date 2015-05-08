#pragma once
#include "ActionTargeted.h"

// grandma can choose to reprimand you for losing the food.
class Reprimand :
	public ActionTargeted
{
public:
	Reprimand(Actor* subject_, Actor* object_, int moments_);
	Reprimand();
	~Reprimand();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};

