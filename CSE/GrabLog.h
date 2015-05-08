#pragma once
#include "Action.h"

// lumberjack chops logs constantly
class GrabLog :
	public Action
{
public:
	GrabLog(Actor* subject_, Stage* location, int moments_);
	GrabLog();
	~GrabLog();

	void Init();

	std::string GetSentence();

	virtual void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};