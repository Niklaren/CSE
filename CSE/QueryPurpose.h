#pragma once
#include "ActionTargeted.h"

// wolf asks red why shes in the forest.
// part of the interrogation sequence.
class QueryPurpose :
	public ActionTargeted
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