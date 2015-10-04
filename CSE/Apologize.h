#pragma once
#include "ActionTargeted.h"

// apologize. in this scenario its for losing the food, but could be made to be more general.
class Apologize :
	public ActionTargeted
{
public:
	Apologize(Actor* subject_, Actor* object_, int moments_);
	Apologize();
	~Apologize();
	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	double NPC_CalculateInclination();
};