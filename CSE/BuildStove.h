#pragma once
#include "Action.h"
class BuildStove :
	public Action
{
public:
	BuildStove(Actor* subject_, int moments_);
	BuildStove();
	~BuildStove();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	void NPC_CalculateInclination(NPC_Actor*);
};