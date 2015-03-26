#pragma once
#include "Action.h"
class Insult :
	public Action
{
public:
	Insult(Actor* subject_, Actor* object_, int moments_);
	~Insult();

	void NPC_CalculateInclination(NPC_Actor*);
	void EmotionalReaction(NPC_Actor*);
};

