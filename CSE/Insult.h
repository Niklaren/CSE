#pragma once
#include "Action.h"
class Insult :
	public Action
{
public:
	Insult(Actor* subject_, Actor* object_, int moments_);
	Insult();
	~Insult();

	void Init();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	void NPC_CalculateInclination(NPC_Actor*);
};

