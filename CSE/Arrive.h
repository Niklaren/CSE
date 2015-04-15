#pragma once
#include "Action.h"
#include "Stage.h"

class Arrive :
	public Action
{
private:

public:
	Arrive(Actor* subject_, int moments_);
	Arrive(Actor* subject_, Stage* s, int moments_ = 1);
	Arrive();
	~Arrive();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();

	virtual bool ReadyToExecute();
};