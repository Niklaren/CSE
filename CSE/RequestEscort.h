#pragma once
#include "ActionTargeted.h"

class RequestEscort :
	public ActionTargeted
{
protected:
	std::string query;
public:
	RequestEscort(Actor* subject_, Actor* object_, int moments_);
	RequestEscort();
	~RequestEscort();
	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
};