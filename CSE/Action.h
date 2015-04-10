#pragma once

#include <string>
#include <assert.h>
#include <vector>
#include <iostream>

#include "WorldStateProperty.h"
#include "Stage.h"

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
	Stage* locationOccured;

	std::vector<WorldStateProperty> conditions;
	std::vector<WorldStateProperty> effects;

	std::vector<std::string> possibleReactions;

	int momentsFromExecution;

	//bool interruptable = true;
	bool reusable = false;

	virtual void Init() {}

	double Blend(double a, double b, double weight);

public:
	Action(Actor* subject_, int momentsFromExecution_);
	Action();
	~Action();

	std::string GetVerb() { return verb; }

	bool HasSubject(){ if (subject != NULL) { return true; } return false; }
	Actor* Get_Subject() { assert(subject != NULL); return subject; }
	void SetSubject(Actor* a){ subject = a; }

	bool HasObject(){ if (object != NULL) { return true; } return false; }
	Actor* Get_Object() { assert(object != NULL); return object; }
	void SetObject(Actor* a){ object = a; }

	bool HasLocation(){ if (locationOccured != NULL) { return true; } return false; }
	Stage* Get_Location() { assert(locationOccured != NULL); return locationOccured; }
	void SetLocation(Stage* l){ locationOccured = l; }

	virtual std::string GetSentence();

	virtual bool React();
	virtual void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*) = 0;
	virtual float NPC_CalculateInclination(){ return 0; }
	//virtual int CalculateInclination(Actor*){ return 0; }

	virtual bool GetUsable() { return true; }
	std::vector<WorldStateProperty> GetConditions() { return conditions; }
	std::vector<WorldStateProperty> GetEffects() { return effects; }

	virtual bool ReadyToExecute();
	void MomentsPass();
	int MomentsSinceExecution() { return -momentsFromExecution; }
	void AddExecutiontime(int time) { momentsFromExecution += time; }

	//bool Interruptable(){ return Interruptable; }
	//void SetInterruptable(bool i){ Interruptable=i; }
	bool Reusable(){ return reusable; }
	void SetReusable(bool b){ reusable=b; }
};
