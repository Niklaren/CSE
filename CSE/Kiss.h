#pragma once
#include "ActionTargeted.h"

// 
class Kiss :
	public ActionTargeted
{
public:
	Kiss(Actor* subject_, Actor* object_, int moments_);
	Kiss();
	~Kiss();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	double NPC_CalculateInclination();
};

