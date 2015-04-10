#pragma once
#include "ActionTargeted.h"

class Answer :
	public ActionTargeted
{
protected:
	std::string query;
public:
	Answer(Actor* subject_, Actor* object_, int moments_);
	Answer();
	~Answer();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
};