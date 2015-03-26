#pragma once
#include "Action.h"

class Punch :
	public Action
{
public:
	Punch(Actor* subject_, Actor* object_, int moments_);
	~Punch();

	void NPC_CalculateInclination(NPC_Actor*);
	void EmotionalReaction(NPC_Actor*);
};

