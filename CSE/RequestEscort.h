#pragma once
#include "ActionTargeted.h"

// ask for an escort home
// can lead to wolf slain ending if successful
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