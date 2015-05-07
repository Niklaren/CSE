#pragma once

#include "HistoryBook.h"
#include "WorldStateProperty.h"

// The representation of the current state of the world
// has an array of all the individual world properties that comprise the scenario.
// and functions for comparing properties to the
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

	WorldStateProperty WSProperties[WSP_Count];
};

