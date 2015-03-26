#pragma once
#include "Action.h"
class Apologize :
	public Action
{
public:
	Apologize(Actor* subject_, Actor* object_, int moments_);
	~Apologize();

	void NPC_CalculateInclination(NPC_Actor*);
	void EmotionalReaction(NPC_Actor*);
};

