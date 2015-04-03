#pragma once
#include "Action.h"

class Greet :
	public Action
{
public:
	Greet(Actor* subject_, Actor* object_, int moments_);
	~Greet();

	void ExecuteConsequences(WorldState*);
	void NPC_CalculateInclination(NPC_Actor*);
	void EmotionalReaction(NPC_Actor*);
};

