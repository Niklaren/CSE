#pragma once
#include "ActionTargeted.h"
class KillWolf :
	public ActionTargeted
{
public:
	KillWolf(Actor* subject_, Actor* object_, int moments_);
	KillWolf();
	~KillWolf();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};