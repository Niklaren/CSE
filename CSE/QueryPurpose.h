#pragma once
#include "Action.h"
class QueryPurpose :
	public Action
{
public:
	QueryPurpose(Actor* subject_, Actor* object_, int moments_);
	QueryPurpose();
	~QueryPurpose();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};