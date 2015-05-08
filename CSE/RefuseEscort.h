#pragma once
#include "ActionTargeted.h"

// lumberjack can refuse your escort request if it does not align with his inclinations.
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