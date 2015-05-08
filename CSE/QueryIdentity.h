#pragma once
#include "Action.h"

// wolf asks red whe she is.
// part of the interrogation sequence
class QueryIdentity :
	public ActionTargeted
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