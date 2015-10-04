#pragma once
#include "ActionTargeted.h"

// wolf greet player (red riding hood)
class WolfGreetRed :
	public ActionTargeted
{
public:
	WolfGreetRed(Actor* subject_, Actor* object_, int moments_);
	WolfGreetRed();
	~WolfGreetRed();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	double NPC_CalculateInclination();
};