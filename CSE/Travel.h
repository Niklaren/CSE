#pragma once
#include "Action.h"
#include "Stage.h"

class Travel :
	public Action
{
private:
	Stage* targetLocation;
public:
	Travel(Actor* subject_, int moments_);
	Travel(Actor* subject_, Stage* s, int moments_);
	Travel();
	~Travel();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();

	virtual bool ReadyToExecute();
};