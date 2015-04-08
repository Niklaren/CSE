#pragma once
#include "Action.h"
class QueryBasket :
	public Action
{
public:
	QueryBasket(Actor* subject_, Actor* object_, int moments_);
	QueryBasket();
	~QueryBasket();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};