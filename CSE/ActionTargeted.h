#pragma once
#include "Action.h"

class ActionTargeted :
	public Action
{
protected:

public:
	ActionTargeted(Actor* subject_, Actor* object_, int moments_);
	ActionTargeted();
	~ActionTargeted();

	//virtual bool React();

	//virtual float CalculateInclination();
};

