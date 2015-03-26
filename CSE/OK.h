#pragma once

#include "Action.h"


class OK : public Action
{
private:
	//Actor* Subject;
	//TCHAR* verb;
	//Actor* Object;



public:
	OK(Actor* subject_, int moments_);
	~OK();
	

	void CalculateInclination(Actor*);
	void EmotionalReaction(NPC_Actor*); // Ok has no emotional reaction??

};
