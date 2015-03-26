#pragma once
#include "Action.h"

class Hug :
	public Action
{
public:
	Hug(Actor* subject_, Actor* object_, int moments_);
	~Hug();

	void NPC_CalculateInclination(NPC_Actor*);
	void EmotionalReaction(NPC_Actor*);
};
