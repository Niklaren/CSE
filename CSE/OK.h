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
	OK();
	~OK();
	
	std::string GetSentence();

	float CalculateInclination();
	void EmotionalReaction(NPC_Actor*); // Ok has no emotional reaction??

};
