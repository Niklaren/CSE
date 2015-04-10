#pragma once
#include "Action.h"
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

