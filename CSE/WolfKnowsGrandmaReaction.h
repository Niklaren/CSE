#pragma once
#include "Action.h"
class WolfKnowsGrandmaReaction :
	public Action
{
public:
	WolfKnowsGrandmaReaction(Actor* subject_, int moments_);
	WolfKnowsGrandmaReaction();
	~WolfKnowsGrandmaReaction();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};