#pragma once
#include "Action.h"

// lumberjack chops logs constantly
class ChopLog :
	public Action
{
public:
	ChopLog(Actor* subject_, Stage* location, int moments_);
	ChopLog();
	~ChopLog();

	void Init();

	std::string GetSentence();

	virtual void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*);
	//double NPC_CalculateInclination();
};