#include "stdafx.h"
//#include "Hug.h"
#include "Actor.h"
#include "NPC_Actor.h"


Hug::Hug(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{
	Init();

	subject = subject_;
	object = object_;
}

Hug::Hug()
{
	Init();
}

Hug::~Hug()
{
}

void Hug::Init()
{
	verb = "Hug";

	//effect
	WorldStateProperty effect1, effect2;
	effect1.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Greet);
	effects.push_back(effect1);
	effect2.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Hug);
	effects.push_back(effect2);

	// conditions
	// same location as target??

}

std::string Hug::GetSentence()
{
	if (subject->GetName() == "You"){
		if (object->GetName() == "Ash")
			return "You give Ash a hug.";
		else if (object->GetName() == "Brooke")
			return "You give Brooke a hug.";
	}
	else if (subject->GetName() == "Ash"){
		return "Ash hugs you tightly.";
	}
	else{
		return "Brooke hugs you.";
	}
	return "hugs!!!";
}

void Hug::ExecuteConsequences(WorldState* ws)
{

}

void Hug::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){

	}
	if (affectingActor == subject){

	}
}

float Hug::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_pPAgreeable();
	double b = static_cast<NPC_Actor*>(subject)->Get_Extraverted();
	double w = static_cast<NPC_Actor*>(subject)->Get_Happy();
	double r = Blend(a, b, w) / 2;
	if (!(subject->GetHistory()->HaventDoneEventBefore(object, "Hug")))	// if the object has hugged during the history we
		r += 0.1;														// may be more inclined to hug
	return r;
}