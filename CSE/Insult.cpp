#include "stdafx.h"
//#include "Insult.h"
#include "Actor.h"
#include "NPC_Actor.h"


Insult::Insult(Actor* subject_, Actor* object_, int moments_ = 1)
	: ActionTargeted(subject_, object_, moments_)
{

	Init();
}

Insult::Insult()
{
	Init();
}

Insult::~Insult()
{
	
}

void Insult::Init()
{
	verb = "Insult";

	//WorldStateProperty effect1, effect2, effect3;
	//effect3.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Insult); // an insult can be responded to with an insult
	//effects.push_back(effect3);

	// no conditions
	// same location as target??

}

void Insult::ExecuteConsequences(WorldState* ws)
{
	//ws->WSProperties[WSP_Insulted].SetWSProperty(WSP_Insulted, WST_bool, true);

	// some effects may only be symbolic or resuable, so it may be wrong to
	// apply every effect indiscriminately (as below)
	//ws->WSProperties[WSP_Insulted] = effects.front();
}

void Insult::EmotionalReaction(NPC_Actor* affectingActor)
{
	if (affectingActor == object){
		//if subject = protagonist
		//affectingActor->Change_ppAgreeable(-0.1);
		//else if subject = B
		//affectingActor->Change_pAgreeable(-0.1);

		//affectingActor->Change_pAgreeable(subject, -0.1)

		affectingActor->Change_Agreeable(-0.15);
		double angerChange = 0.15;
		affectingActor->Change_Angry(angerChange);
	}
}

double Insult::NPC_CalculateInclination()
{
	/*if (affectingActor == object){
		double punch_inclination = -affectingActor->Get_Agreeable();//Blend(-affectingActor->Get_Agreeable())
		double insult_inclination = -affectingActor->Get_Agreeable();//Blend(-affectingActor->Get_Agreeable())
		if (punch_inclination > 0.5)
			affectingActor->Plan("Punch", 1, subject);
		else if (insult_inclination > 0.0)
			affectingActor->Plan("Insult", 1, subject);

	}*/
	return 0;
}
