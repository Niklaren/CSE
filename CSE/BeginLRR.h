#pragma once

#include "Action.h"


class BeginLRR : public Action
{
public:
	Actor* player,* wolf,* lumberjack,* grandma;


	BeginLRR();
	BeginLRR(Actor* subject_, Actor* p, Actor* w, Actor* l, Actor* g, int moments_);
	~BeginLRR();

	virtual std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	//virtual float NPC_CalculateInclination();
	virtual void EmotionalReaction(NPC_Actor*);
};

