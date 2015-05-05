#pragma once

#include <string>

using namespace std;

enum eWorldStateEvents
{
	WSE_Invalid = -1,
	WSE_MoodChange,			//may need ones for target & self??
	WSE_PersonalityChange,
	WSE_FoodGiven,
	WSE_RequestEntry,
	WSE_RequestEscort,
	WSE_WolfKnowsGrandma,
	WSE_AskDirections,
	WSE_Punch,
	WSE_Hug,
	WSE_Apologize,
	WSE_Greet,
	WSE_Insult
};
enum eWorldStateProperties_Key
{
	WSP_Invalid = -1,
	WSP_ReactToWorldStateEvent, // ?
	WSP_RedHome,
	WSP_LunchDelivered,
	WSP_DeliveryFailed,
	WSP_Forgiven,
	WSP_Reprimanded,
	WSP_WolfGreetRed,
	WSP_Greeting,
	WSP_QueryRed,
	WSP_WolfHungry,
	WSP_WolfDead,
	WSP_WolfHasLunch,
	WSP_WolfKnowsGrandma,
	WSP_RedPanicked,
	WSP_RedDistracted,
	WSP_RedEaten,
	WSP_GrandmaEaten,
	WSP_HaveEscort,
	WSP_DoorOpen,
	WSP_HaveFlowers,
	WSP_WrongDirections,
	WSP_Location,
	WSP_JackHasLumber,
	WSP_LumberOnStump,
	WSP_LumberChopped,
	WSP_Count
};
const string WorldStateProperties_Key[WSP_Count]
{
	"WSP_ReactToWorldStateEvent",
	"WSP_RedHome",
	"WSP_LunchDelivered",
	"WSP_DeliveryFailed",
	"WSP_Forgiven",
	"WSP_Reprimanded",
	"WSP_WolfGreetRed",
	"WSP_Greeting",
	"WSP_QueryRed",
	"WSP_WolfHungry",
	"WSP_WolfDead",
	"WSP_WolfHasLunch",
	"WSP_WolfKnowsGrandma",
	"WSP_RedPanicked",
	"WSP_RedDistracted",
	"WSP_RedEaten",
	"WSP_GrandmaEaten",
	"WSP_HaveEscort",
	"WSP_DoorOpen",
	"WSP_HaveFlowers",
	"WSP_WrongDirections",
	"WSP_Location",
	"WSP_JackHasLumber",
	"WSP_LumberOnStump",
	"WSP_LumberChopped",
};
enum eWorldStateProperties_Type
{
	WST_Invalid = -1,
	WST_int,
	//WST_greater,
	WST_float,
	WST_bool,
	WST_worldStateEvent,
	WST_variable
};


//custom key/value Pair
struct WorldStateProperty
{

	eWorldStateProperties_Key Key;
	eWorldStateProperties_Type Type;
	
	int ivalue;
	float fvalue;
	bool bvalue;
	eWorldStateEvents evalue;

	/*union{
		int ivalue;
		float fvalue;
		bool bvalue;
	};*/

	WorldStateProperty()
	{
		Key = WSP_Invalid;
		Type = WST_Invalid;
		ivalue = 0;
		fvalue = 0;
		bvalue = false;
		evalue = WSE_Invalid;
	}

	void SetWSProperty(WorldStateProperty* ws)
	{
		Key = ws->Key;
		Type = ws->Type;
		ivalue = ws->ivalue;
		fvalue = ws->fvalue;
		bvalue = ws->bvalue;
		evalue = ws->evalue;
	}

	void SetWSProperty(eWorldStateProperties_Key Key_, eWorldStateProperties_Type Type_, int i_)
	{
		Key = Key_;
		Type = Type_;
		if (Type == WST_int)
			ivalue = i_;
	}

	void SetWSProperty(eWorldStateProperties_Key Key_, eWorldStateProperties_Type Type_, float f_)
	{
		Key = Key_;
		Type = Type_;
		if (Type == WST_float)
			fvalue = f_;
	}

	void SetWSProperty(eWorldStateProperties_Key Key_, eWorldStateProperties_Type Type_, bool b_)
	{
		Key = Key_;
		Type = Type_;
		if (Type == WST_bool)
			bvalue = b_;
	}

	void SetWSProperty(eWorldStateProperties_Key Key_, eWorldStateProperties_Type Type_, eWorldStateEvents e_)
	{
		Key = Key_;
		Type = Type_;
		if (Type == WST_worldStateEvent)
			evalue = e_;
	}

	void SetWSProperty(eWorldStateProperties_Key Key_, eWorldStateProperties_Type Type_)
	{
		Key = Key_;
		Type = Type_;
	}

	void SetValue(bool b)
	{
		if (Type == WST_bool)
			bvalue = b;
	}

	void SetValue(int i)
	{
		if (Type == WST_int)
			ivalue = i;
	}

	void SetValue(eWorldStateEvents e)
	{
		if (Type == WST_worldStateEvent)
			evalue = e;
	}

	void ChangeValue(int i)
	{
		if (Type == WST_int)
			ivalue += i;
	}

	WorldStateProperty& operator=(const WorldStateProperty& other)
	{
		Key = other.Key;
		Type = other.Type;
		ivalue = other.ivalue;
		fvalue = other.fvalue;
		bvalue = other.bvalue;
		evalue = other.evalue;

		return *this;
	}

	bool operator== (const WorldStateProperty& other)
	{
		if ((Key == other.Key) && (Type == other.Type)){
			if ((Type == WST_int) && (ivalue == other.ivalue))
				return true;
			if ((Type == WST_float) && (fvalue == other.fvalue))
				return true;
			if ((Type == WST_bool) && (bvalue == other.bvalue))
				return true;
			if ((Type == WST_worldStateEvent) && (evalue == other.evalue))
				return true;
			if (Type == WST_variable)
				return true;
		}
		
		return false;
	}

	string TextForOutput(int i)
	{
		
		if (Type == WST_int)
			return WorldStateProperties_Key[i] + ": " + std::to_string(ivalue) + "\n";
		if (Type == WST_float)
			return WorldStateProperties_Key[i] + ": " + std::to_string(fvalue) + "\n";
		if (Type == WST_bool)
			return WorldStateProperties_Key[i] + ": " + std::to_string(bvalue) + "\n";
		if (Type == WST_worldStateEvent)
			return WorldStateProperties_Key[i] + ": " + "\n";
		if (Type == WST_variable)
			return WorldStateProperties_Key[i] + ": " + "\n";

		return WorldStateProperties_Key[i] + ": " + "\n";
	}
};