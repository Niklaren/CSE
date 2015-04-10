#include "stdafx.h"
#include "WorldState.h"


WorldState::WorldState()
{
	WSProperties[WSP_ReactToWorldStateEvent].SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Invalid);
	WSProperties[WSP_Location].SetWSProperty(WSP_Location, WST_variable, WSE_Invalid);

	WSProperties[WSP_RedHome].SetWSProperty(WSP_RedHome, WST_bool, false);
	WSProperties[WSP_LunchDelivered].SetWSProperty(WSP_LunchDelivered, WST_bool, false);
	WSProperties[WSP_WolfGreetRed].SetWSProperty(WSP_WolfGreetRed, WST_bool, false);
	//wsp_greeting
	WSProperties[WSP_QueryRed].SetWSProperty(WSP_QueryRed, WST_int, 0);
	WSProperties[WSP_WolfHungry].SetWSProperty(WSP_WolfHungry, WST_bool, true);
	WSProperties[WSP_WolfHasLunch].SetWSProperty(WSP_WolfHasLunch, WST_bool, false);
	WSProperties[WSP_WolfKnowsGrandma].SetWSProperty(WSP_WolfKnowsGrandma, WST_bool, false);
	WSProperties[WSP_RedPanicked].SetWSProperty(WSP_RedPanicked, WST_bool, false);
	WSProperties[WSP_RedEaten].SetWSProperty(WSP_RedEaten, WST_bool, false);
	WSProperties[WSP_GrandmaEaten].SetWSProperty(WSP_GrandmaEaten, WST_bool, false);
	WSProperties[WSP_DoorOpen].SetWSProperty(WSP_DoorOpen, WST_bool, false);
	WSProperties[WSP_FlowersPicked].SetWSProperty(WSP_FlowersPicked, WST_bool, false);
	WSProperties[WSP_JackHasLumber].SetWSProperty(WSP_JackHasLumber, WST_bool, false);
	WSProperties[WSP_LumberOnStump].SetWSProperty(WSP_LumberOnStump, WST_bool, false);
	WSProperties[WSP_LumberChopped].SetWSProperty(WSP_LumberChopped, WST_int, 0);
	



}

WorldState::~WorldState()
{
}

void WorldState::LoadFromFile(string FileName)
{

}

bool WorldState::MeetsWorldState(vector<WorldStateProperty> wsp)
{
	// if any of the passed in properties do not match then it does not meet the current world state
	for (unsigned int i(0); i < wsp.size(); i++){
		if (!(wsp[i] == WSProperties[wsp[i].Key]))
			return false;
	}

	return true;
}

bool WorldState::MeetsWorldState(WorldStateProperty wsp)
{
	// if any of the passed in property does not match then it does not meet the current world state
	if (!(wsp == WSProperties[wsp.Key])){
			return false;
	}

	return true;
}

bool WorldState::IsCloser(WorldStateProperty effect, WorldStateProperty goal)
{
	if ((effect.Key != goal.Key) || (effect.Type != goal.Type))
		return false;

	if ((goal.Type == WST_bool) && (effect.bvalue == goal.bvalue) && (WSProperties[goal.Key].bvalue != goal.bvalue))
		return true;
	if (goal.Type == WST_int){
		unsigned int real_diff = goal.ivalue - WSProperties[goal.Key].ivalue;
		unsigned int eff_diff = goal.ivalue - (WSProperties[goal.Key].ivalue + effect.ivalue);
		if (eff_diff < real_diff)
			return true;
	}
	if ((goal.Type == WST_float) && (effect.fvalue == goal.fvalue) && (WSProperties[goal.Key].fvalue != goal.fvalue))
		return true;
	if ((goal.Type == WST_worldStateEvent) && (effect.evalue == goal.evalue))
		return true;
	if ((goal.Type == WST_variable))
		return true;

	return false;
}