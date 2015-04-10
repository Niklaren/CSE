#pragma once
#include "Action.h"

class OpenDoor :
	public Action
{
public:
	OpenDoor(Actor* subject_, int moments_);
	OpenDoor();
	~OpenDoor();

	void Init();

	std::string GetSentence();

	virtual void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*);
	float NPC_CalculateInclination();
};
