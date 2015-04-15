#pragma once
#include "ActionTargeted.h"
class Intimidate :
	public ActionTargeted
{
public:
	Intimidate(Actor* subject_, Actor* object_, int moments_);
	Intimidate();
	~Intimidate();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};