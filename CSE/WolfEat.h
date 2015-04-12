#pragma once
#include "ActionTargeted.h"
class WolfEat :
	public ActionTargeted
{
public:
	WolfEat(Actor* subject_, Actor* object_, int moments_);
	WolfEat();
	~WolfEat();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};