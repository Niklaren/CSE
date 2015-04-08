#pragma once
#include "Action.h"
class QueryIdentity :
	public Action
{
public:
	QueryIdentity(Actor* subject_, Actor* object_, int moments_);
	QueryIdentity();
	~QueryIdentity();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};