#pragma once
#include "ActionTargeted.h"

// lumberjack can slay the wolf with his axe. leads to wolf slain ending
class KillWolf :
	public ActionTargeted
{
public:
	KillWolf(Actor* subject_, Actor* object_, int moments_);
	KillWolf();
	~KillWolf();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	double NPC_CalculateInclination();
};