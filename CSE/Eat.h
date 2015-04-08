#pragma once
#include "Action.h"
class Eat :
	public Action
{
public:
	Eat(Actor* subject_, Actor* object_, int moments_);
	Eat(Actor* subject_, int moments_);
	Eat();
	~Eat();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};