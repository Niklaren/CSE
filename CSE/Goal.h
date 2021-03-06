#pragma once
#include "WorldStateProperty.h"

class NPC_Actor;

// Goals are a world state property that the NPC agents want to set
class Goal :
	public WorldStateProperty
{
private:
	//NPC_Actor* target;	// maybe not all goals have targets though
	//Stage location

	float relevance;
	string name;
public:
	Goal();
	Goal(float relevance_, string name_);
	//Goal(float relevance, NPC_Actor*);
	~Goal();

	void SetGoal(Goal);

	// how high priority the goal is. higher = more important
	void SetRelevance(float r) { relevance = r; }
	float CalculateRelevance();
	
	//void SetTarget(NPC_Actor* t) { target = t; }
	//NPC_Actor* GetTarget() { return target; }

	string GetName() { return name; }
};

