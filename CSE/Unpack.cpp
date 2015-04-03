#include "stdafx.h"
//#include "Unpack.h"
#include "Actor.h"
#include "NPC_Actor.h"


Unpack::Unpack(Actor* subject_, int moments_ = 1)
	: Action(moments_)
{
	subject = subject_;
	//object = object_;

	Init();
}

Unpack::Unpack()
{
	Init();
}

Unpack::~Unpack()
{

}

void Unpack::Init()
{
	verb = "Unpack";

	//effect
	WorldStateProperty effect1;
	effect1.SetWSProperty(WSP_Unpacked, WST_bool, true);
	effects.push_back(effect1);

	// no conditions
	// same location?
}

std::string Unpack::GetSentence()
{
	return subject->GetName() + " unpacks the tripod, pot and food";
}

void Unpack::ExecuteConsequences(WorldState* ws)
{
	ws->WSProperties[WSP_Unpacked].SetWSProperty(WSP_Unpacked, WST_bool, true);

}

void Unpack::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){

	}
	if (affectingActor == subject){

	}
}

void Unpack::NPC_CalculateInclination(NPC_Actor* affectingActor)
{

}