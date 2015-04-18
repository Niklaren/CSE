#pragma once
#include "ActionTargeted.h"
class Thank :
	public ActionTargeted
{
public:
	Thank(Actor* subject_, Actor* object_, int moments_);
	Thank();
	~Thank();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};
