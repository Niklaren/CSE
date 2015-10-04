#pragma once
#include "Action.h"

// grandma will open the door in response to a request for entry
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
	//double NPC_CalculateInclination();
};
