#pragma once
#include "Action.h"

// Go Home action allows the player to 'give up' and go home at anytime as a free choice.
class GoHome :
	public Action
{
public:
	GoHome(Actor* subject_, int moments_);
	~GoHome();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
};

