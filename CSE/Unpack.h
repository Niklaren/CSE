#pragma once
#include "Action.h"
class Unpack :
	public Action
{
public:
	Unpack(Actor* subject_, int moments_);
	Unpack();
	~Unpack();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};