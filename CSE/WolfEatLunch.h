#pragma once
#include "Action.h"

// wolf eat lunch. requres wolf to be in possesion of the lunch.
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
	double NPC_CalculateInclination();
};

