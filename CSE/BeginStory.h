#pragma once

//forward declaration
#include "Action.h"
//class Action;



class BeginStory : public Action
{
public:
	Actor* extraActor;

	BeginStory();
	//BeginStory(Actor &subject_);
	BeginStory(Actor* subject_, Actor* object_, Actor* extra_, int moments_);
	~BeginStory();

	virtual std::string GetSentence();

	virtual void NPC_CalculateInclination(NPC_Actor*);
	virtual void EmotionalReaction(NPC_Actor*);
};

