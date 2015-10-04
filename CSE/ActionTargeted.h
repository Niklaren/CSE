#pragma once
#include "Action.h"

// some action definitely have targets. should move some of the Actor* object over,but would require redoing some if(object) checks
class ActionTargeted :
	public Action
{
protected:

public:
	ActionTargeted(Actor* subject_, Actor* object_, int moments_);
	ActionTargeted();
	~ActionTargeted();

	virtual bool ReadyToExecute();

	virtual bool React();

	//virtual double CalculateInclination();
};

