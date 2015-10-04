#pragma once

#include "Action.h"


class Player_Actor;

class BeginLRR : public Action
{
public:
	Player_Actor* red;
	NPC_Actor* wolf,* lumberjack,* grandma;
	Stage* path, *forest, *cabin, *lodge, *offstage;

	BeginLRR();
	BeginLRR(Actor* subject_, Player_Actor* p, NPC_Actor* w, NPC_Actor* l, NPC_Actor* g, int moments_=1);
	~BeginLRR();

	virtual std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	//virtual double NPC_CalculateInclination();
	virtual void EmotionalReaction(NPC_Actor*);
};

