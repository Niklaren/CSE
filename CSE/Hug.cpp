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
		if (object->GetName() == "Grandma")
			return "You hug grandma tightly.";
	}
	else if (subject->GetName() == "Grandma"){
		if (object->GetName() == "You")
			return "Grandma embraces you warmly.";
	}
	return "hugs!!!";
}

void Hug::ExecuteConsequences(WorldState* ws)
{
	Action::ExecuteConsequences(ws);

	subject->RemoveAction("Hug");
	if (subject->GetName() != "You")
		ws->WSProperties[WSP_ReactToWorldStateEvent].SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Hug);
}

void Hug::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		affectingActor->Change_pAgreeable(0.15,subject->GetID());
		affectingActor->Change_pExtraverted(0.1,subject->GetID());
		affectingActor->Change_Angry(-0.1);
		affectingActor->Change_Happy(0.1);
	}
	if (affectingActor == subject){
		affectingActor->Change_Happy(0.05);
		affectingActor->Change_pAgreeable(0.1, object->GetID());
	}
}

float Hug::NPC_CalculateInclination()
{
	double a = static_cast<NPC_Actor*>(subject)->Get_pAgreeable(object->GetID());
	double b = static_cast<NPC_Actor*>(subject)->Get_Extraverted();
	double w = static_cast<NPC_Actor*>(subject)->Get_Happy();
	double r = Blend(a, b, w);
	return r;
}