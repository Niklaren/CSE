#pragma once
#include "Action.h"
#include "Stage.h"

class Leave :
	public Action
{
private:

public:
	Leave(Actor* subject_, int moments_);
	Leave();
	~Leave();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();

	virtual bool ReadyToExecute();
};