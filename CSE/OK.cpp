#include "stdafx.h"
#include "OK.h"


OK::OK(Actor* subject_, int moments_ = 1)
	: Action(subject_, moments_)
{
	verb = "OK";
}

OK::OK()
{
	//WorldStateProperty effect1, effect2, effect3, effect4, effect5, effect6, effect7;
	//effect1.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Greet);
	//effect2.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_MoodChange);
	//effect3.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_PersonalityChange);
	//effect4.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Punch);
	//effect5.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Hug);
	//effect6.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Greet);
	//effect7.SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Insult);
	//effects.push_back(effect1);
	//effects.push_back(effect2);
	//effects.push_back(effect3);
	//effects.push_back(effect4);
	//effects.push_back(effect5);
	//effects.push_back(effect6);
	//effects.push_back(effect7);

	WorldStateProperty effect0;
	//effect0.SetWSProperty(WSP_Greeting, WST_bool, true);

	//no conditions
}

OK::~OK()
{
}

std::string OK::GetSentence()
{
	return "no response.";
}

float OK::CalculateInclination()
{
	return 0.75;
}

void OK::EmotionalReaction(NPC_Actor* affectingActor)
{

}
