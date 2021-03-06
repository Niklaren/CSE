#pragma once
#include "ActionTargeted.h"

// ask directions. prompts a response to this event
class AskDirections :
	public ActionTargeted
{
public:
	AskDirections(Actor* subject_, Actor* object_, int moments_);
	AskDirections();
	~AskDirections();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
};