#pragma once
#include "ActionTargeted.h"

class Greet :
	public ActionTargeted
{
public:
	Greet(Actor* subject_, Actor* object_, int moments_);
	Greet();
	~Greet();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	double NPC_CalculateInclination();
};