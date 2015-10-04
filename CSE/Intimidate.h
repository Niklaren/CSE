#pragma once
#include "ActionTargeted.h"

// wolf intimidates the character to give them some warning they are about to be eaten
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
	double NPC_CalculateInclination();
};