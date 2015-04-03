#pragma once

#include "HistoryBook.h"
#include "WorldStateProperty.h"

class WorldState
{
public:
	WorldState();
	~WorldState();

	void LoadFromFile(string FileName);
	bool MeetsWorldState(vector<WorldStateProperty>);
	bool MeetsWorldState(WorldStateProperty wsp);

	//eventhistory?
//protected:
	WorldStateProperty WSProperties[WSP_Count];
};

