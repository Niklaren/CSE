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

// An action represents the things characters can do to affect the world
// Actions must have a subject. but need not have an object.
// Actions that are to be performed by NPCs should have conditions and effects, which are used by the planner.
// Actions can be in a characters memeory as an available action they could perform. in their plans as something they will attempt to do.
// and finally in the history book as an event that has previously occured.
class Action
{
protected:
	Actor* subject;
	std::string verb;
	Actor* object;
	Stage* locationOccured;

	std::vector<WorldStateProperty> conditions;
	std::vector<WorldStateProperty> effects;

	int momentsFromExecution;	// how long until/since execution. negative values (typically) represent past events

	//bool interruptable = true;
	bool reusable = false;	// currently used in planner. could be used to remove actions form NPCs after they have used them also.

	virtual void Init() {}

	double Blend(double a, double b, double weight);	// function to weight factors in calculating inclination to perform an action

public:
	Action(Actor* subject_, int momentsFromExecution_);
	Action();
	~Action();

	// set, get & check subject/ver/object/location/sentence
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

	// actions can specify how they're reacted to and by whom. what consequences they have. and what emotional response they illicit
	virtual bool React();
	virtual void ExecuteConsequences(WorldState*);
	virtual void EmotionalReaction(NPC_Actor*);

	// actions should also specify how the actor is inclined to perform it. can range from -1(hate to do) to 1(love to do it)
	virtual float NPC_CalculateInclination(){ return 0; } // 0 by default, ambivilent. most actions for NPCs should likely avoid this

	virtual bool GetUsable() { return true; }	// actions can have conditions under which they're unusable. eg. shoot, with no gun
	std::vector<WorldStateProperty> GetConditions() { return conditions; }
	std::vector<WorldStateProperty> GetEffects() { return effects; }

	virtual bool ReadyToExecute();
	// track moments to/from execution for the action
	void MomentsPass();
	int MomentsSinceExecution() { return -momentsFromExecution; }
	void AddExecutionTime(int time) { momentsFromExecution += time; }
	void SetExecutionTime(int time) { momentsFromExecution = time; }

	//bool Interruptable(){ return Interruptable; }
	//void SetInterruptable(bool i){ Interruptable=i; }
	bool Reusable(){ return reusable; }
	void SetReusable(bool b){ reusable=b; }
};
