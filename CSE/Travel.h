#pragma once
#include "Action.h"
#include "Stage.h"

// Travel Action. move form one location to another different one.
// This used to be plannable by the planner. but for the purposes of this demo was cut back.
// future work could be to improve how this is planned, implemented and costed.
class Travel :
	public Action
{
private:
	Stage* targetLocation;	// need a target location to travel to.
public:
	Travel(Actor* subject_, int moments_);
	Travel(Actor* subject_, Stage* s, int moments_=1, string verb_ = "Travel");
	Travel();
	~Travel();

	void Init();

	std::string GetSentence();

	virtual void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*);
	virtual double NPC_CalculateInclination();

	virtual bool ReadyToExecute();
};