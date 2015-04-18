#pragma once
#include "ActionTargeted.h"

class RefuseEscort :
	public ActionTargeted
{
public:
	RefuseEscort(Actor* subject_, Actor* object_, int moments_);
	RefuseEscort();
	~RefuseEscort();
	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};