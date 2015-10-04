#pragma once
#include "ActionTargeted.h"
class Insult :
	public ActionTargeted
{
public:
	Insult(Actor* subject_, Actor* object_, int moments_);
	Insult();
	~Insult();

	void Init();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	double NPC_CalculateInclination();
};

