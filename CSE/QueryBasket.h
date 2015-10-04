#pragma once
#include "ActionTargeted.h"

// wolf asks red whats in the box.
// part of the interrogation sequence
class QueryBasket :
	public ActionTargeted
{
public:
	QueryBasket(Actor* subject_, Actor* object_, int moments_);
	QueryBasket();
	~QueryBasket();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	double NPC_CalculateInclination();
};