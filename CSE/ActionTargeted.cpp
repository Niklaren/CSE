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

//bool ActionTargeted::React()
//{
//	if (HasSubject())
//		subject->React();
//	if (HasObject())
//		object->React();
//}
