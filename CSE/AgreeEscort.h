#pragma once
#include "ActionTargeted.h"

// the lumberjack can agree to escort you, which leads to the wolf slain ending.
class AgreeEscort :
	public ActionTargeted
{
	Stage* escortTo;
public:
	AgreeEscort(Actor* subject_, Actor* object_, int moments_);
	AgreeEscort();
	~AgreeEscort();
	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};