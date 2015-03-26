#pragma once
#include "Action.h"

class Intervene :
	public Action
{
public:
	NPC_Actor* a1;
	NPC_Actor* a2;

	Intervene(Actor* subject_, NPC_Actor* a1, NPC_Actor* a2, int moments_);
	~Intervene();

	virtual void React();
	void NPC_CalculateInclination(NPC_Actor*);
	void EmotionalReaction(NPC_Actor*);
};
