#include "stdafx.h"
#include "OK.h"


OK::OK(Actor* subject_, int moments_ = 1)
	: Action(moments_)
{
	subject = subject_;
	verb = "OK";

}


OK::~OK()
{
}

void OK::CalculateInclination(Actor* affectingActor)
{
	return;
}

void OK::EmotionalReaction(NPC_Actor* affectingActor)
{

}
