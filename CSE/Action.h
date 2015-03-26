#pragma once

#include <string>
#include <assert.h>
#include <vector>
#include <iostream>

//forward declaration
class Actor;
class NPC_Actor;

class Action
{
protected:
	Actor* subject;
	std::string verb;
	Actor* object;

	std::vector<std::string> possibleReactions;

	int momentsFromExecution;

	double Blend(double a, double b, double weight);

public:
	Action(int momentsFromExecution_);
	~Action();

	virtual std::string GetSentence();

	virtual void React();
	virtual void EmotionalReaction(NPC_Actor*) = 0;
	virtual void NPC_CalculateInclination(NPC_Actor*){ return; }
	virtual void CalculateInclination(Actor*){ return; }

	std::string GetVerb() { return verb; }
	bool HasSubject(){ if (subject != NULL) { return true; } return false; }
	Actor* GetSubject() { assert(subject != NULL); return subject; }
	bool HasObject(){ if (object != NULL) { return true; } return false; }
	Actor* GetObject() { assert(object != NULL); return object; }

	bool ReadyToExecute();
	void MomentsPass();
	int MomentsSinceExecution() { return -momentsFromExecution; }
};

