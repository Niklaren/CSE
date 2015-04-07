#pragma once

#include <string>

using namespace std;

enum eWorldStateEvents
{
	WSE_Invalid = -1,
	WSE_MoodChange,			//may need ones for target & self??
	WSE_PersonalityChange,
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
	WSP_FoodEaten,
	WSP_FoodCooked, //cook poorly or well
	WSP_Unpacked,
	WSP_StoveReady,
	WSP_FireBuilt,
	WSP_WoodCollected, // collect proper logs or just twigs
	WSP_WaterFetched, // perhaps not enough?
	WSP_Greeting,
	WSP_Insulted,
	WSP_Punched,
	WSP_Location,
	WSP_Count
};
//const string WorldStateProperties_Key[WSP_Count]
//{
//	"WSP_ReactToWorldStateEvent",
//	"WSP_Insulted",
//	"WSP_Punched"
//
//};
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


};