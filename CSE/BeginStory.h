#pragma once

//forward declaration
#include "ActionTargeted.h"
//class Action;



class BeginStory : public ActionTargeted
{
public:
	Actor* extraActor;

	BeginStory();
	//BeginStory(Actor &subject_);
	BeginStory(Actor* subject_, Actor* object_, int moments_);
	~BeginStory();

	virtual std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	//virtual float NPC_CalculateInclination();
	virtual void EmotionalReaction(NPC_Actor*);
};

