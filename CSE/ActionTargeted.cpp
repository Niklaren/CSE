#include "stdafx.h"
#include "ActionTargeted.h"
#include "Actor.h"

ActionTargeted::ActionTargeted(Actor* subject_, Actor* object_, int moments_)
	: Action(subject_, moments_)
{
	object = object_;
}

ActionTargeted::ActionTargeted()
{
}

ActionTargeted::~ActionTargeted()
{
}

bool ActionTargeted::ReadyToExecute()
{
	if (!Action::ReadyToExecute())
		return false;

	if (subject->GetLocation() != object->GetLocation()){ // if we're not in the same place as the target. we should move there.
		subject->Wait(1);
		subject->Plan("Travel", object->GetLocation(), 0);
		return false;
	}
	return true;
}

// default reaction (subject) and object reaction
bool ActionTargeted::React()
{
	bool reaction = false;

	if(Action::React())
		reaction = true;
	if(object->React())
		reaction=true;

	return reaction;
}
