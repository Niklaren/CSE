#pragma once

#include <string>
#include <assert.h>
#include <vector>
#include <iostream>

#include "WorldStateProperty.h"

//forward declaration
class Actor;
class NPC_Actor;
class WorldState;

class Action
{
protected:
	Actor* subject;
	std::string verb;
	Actor* object;

	std::vector<WorldStateProperty> conditions;
	std::vector<WorldStateProperty> effects;

	std::vector<std::string> possibleReactions;

	int momentsFromExecution;

	virtual void Init() {}

	double Blend(double a, double b, double weight);

public:
	Action(int momentsFromExecution_);
	Action();
	~Action();

	void SetSubject(Actor* a){ subject = a; }
	void SetObject(Actor* a){ object = a; }

	virtual std::string GetSentence();

	virtual void React();
	virtual void ExecuteConsequences(WorldState*) { return; }
	virtual void EmotionalReaction(NPC_Actor*) = 0;
	virtual void NPC_CalculateInclination(NPC_Actor*){ return; }
	virtual void CalculateInclination(Actor*){ return; }

	virtual bool GetUsable() { return true; }
	std::vector<WorldStateProperty> GetConditions() { return conditions; }
	std::vector<WorldStateProperty> GetEffects() { return effects; }

	std::string GetVerb() { return verb; }
	bool HasSubject(){ if (subject != NULL) { return true; } return false; }
	Actor* GetSubject() { assert(subject != NULL); return subject; }
	bool HasObject(){ if (object != NULL) { return true; } return false; }
	Actor* GetObject() { assert(object != NULL); return object; }

	bool ReadyToExecute();
	void MomentsPass();
	int MomentsSinceExecution() { return -momentsFromExecution; }
	void AddExecutiontime(int time) { momentsFromExecution += time; }
};

