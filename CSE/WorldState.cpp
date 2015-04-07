#include "stdafx.h"
#include "WorldState.h"


WorldState::WorldState()
{
	WSProperties[WSP_ReactToWorldStateEvent].SetWSProperty(WSP_ReactToWorldStateEvent, WST_worldStateEvent, WSE_Invalid);
	WSProperties[WSP_FoodEaten].SetWSProperty(WSP_FoodEaten, WST_bool, false);
	WSProperties[WSP_FoodCooked].SetWSProperty(WSP_FoodCooked, WST_bool, false);
	WSProperties[WSP_Unpacked].SetWSProperty(WSP_Unpacked, WST_bool, false);
	WSProperties[WSP_StoveReady].SetWSProperty(WSP_StoveReady, WST_bool, false);
	WSProperties[WSP_FireBuilt].SetWSProperty(WSP_FireBuilt, WST_bool, false);
	WSProperties[WSP_WoodCollected].SetWSProperty(WSP_WoodCollected, WST_bool, false);
	WSProperties[WSP_WaterFetched].SetWSProperty(WSP_WaterFetched, WST_int, 0);
	WSProperties[WSP_Greeting].SetWSProperty(WSP_Greeting, WST_bool, false);
	WSProperties[WSP_Punched].SetWSProperty(WSP_Punched, WST_bool, false);
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
		int real_diff = goal.ivalue - WSProperties[goal.Key].ivalue;
		int eff_diff = goal.ivalue - (WSProperties[goal.Key].ivalue + effect.ivalue);
		if (eff_diff < real_diff)
			return true;
	}
	if ((goal.Type == WST_float) && (effect.fvalue == goal.fvalue) && (WSProperties[goal.Key].fvalue != goal.fvalue))
		return true;
	if ((goal.Type == WST_worldStateEvent) && (effect.evalue == goal.evalue))
		return true;

	return false;
}