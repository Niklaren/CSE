#pragma once

#include "HistoryBook.h"

enum eWorldStateEvents
{
	WSP_FoodCooked = 0
};
enum eWorldStateProperties_Key
{
	WSP_Invalid = -1,
	WSP_FoodAvailable,
	WSP_Count
};
const string WorldStateProperties_Key[WSP_Count]
{
	"WSP_FoodAvailable"
};
enum eWorldStateProperties_Type
{
	WST_int,
	WST_bool,
	WST_variable
};


//custom key/value Pair
struct WorldStateProperty
{

	eWorldStateProperties_Key Key;
	eWorldStateProperties_Type Type;
	int value;
};


class WorldState
{
public:
	WorldState();
	~WorldState();
};

