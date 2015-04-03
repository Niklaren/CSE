#pragma once
#include "Action.h"
class CookGood :
	public Action
{
public:
	CookGood(Actor* subject_, int moments_);
	CookGood();
	~CookGood();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	void NPC_CalculateInclination(NPC_Actor*);
};