#pragma once
#include "WorldStateProperty.h"

class NPC_Actor;

class Goal :
	public WorldStateProperty
{
private:
	NPC_Actor* target;	// maybe not all goals have targets though
	//Stage location

	float Relevance; // may be unecessary if we always have a value from calculate relevance
public:
	Goal();
	Goal(float relevance, NPC_Actor*);
	~Goal();

	void SetGoal(Goal);

	void SetRelevance(float r) { Relevance = r; }
	float CalculateRelevance();
	
	void SetTarget(NPC_Actor* t) { target = t; }
	NPC_Actor* GetTarget() { return target; }
};

