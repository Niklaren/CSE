#pragma once
#include "ActionTargeted.h"

// if you interact with her positively before telling her you lost the food grandma can forgive you.
class Forgive :
	public ActionTargeted
{
public:
	Forgive(Actor* subject_, Actor* object_, int moments_);
	Forgive();
	~Forgive();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	double NPC_CalculateInclination();
};