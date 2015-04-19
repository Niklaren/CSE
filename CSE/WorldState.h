#pragma once

#include "HistoryBook.h"
#include "WorldStateProperty.h"

class WorldState
{
public:
	WorldState();
	~WorldState();

	void LoadFromFile(string FileName);
	void WriteToFile(int);

	bool MeetsWorldState(vector<WorldStateProperty>);
	bool MeetsWorldState(WorldStateProperty wsp);

	bool IsCloser(WorldStateProperty effect, WorldStateProperty goal);

	//eventhistory?
//protected:
	WorldStateProperty WSProperties[WSP_Count];
};

