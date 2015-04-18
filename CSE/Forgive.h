#pragma once
#include "ActionTargeted.h"
class Forgive :
	public ActionTargeted
{
public:
	Forgive(Actor* subject_, Actor* object_, int moments_);
	Forgive();
	~Forgive();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};