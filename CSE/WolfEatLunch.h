#pragma once
#include "Action.h"
class WolfEatLunch :
	public Action
{
public:
	WolfEatLunch(Actor* subject_, int moments_);
	WolfEatLunch();
	~WolfEatLunch();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};

