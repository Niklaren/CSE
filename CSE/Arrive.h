#pragma once
#include "Action.h"
#include "Stage.h"

// after characters leave an area they arrive elsewhere (in the same moment (could be made to take more moments)).
// since there's a leave and an arrive, events occur at both locations. meaning reactions can happen and sentences displayed for both.
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

	virtual void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*);
	virtual double NPC_CalculateInclination();

	virtual bool ReadyToExecute();
};