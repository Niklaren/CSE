#include "stdafx.h"
#include "DramaManager.h"


DramaManager::DramaManager(Stage* s, WorldState* ws_, HistoryBook& hb)
	: Actor("fate", s, hb)
{
	ws = ws_;
}


DramaManager::~DramaManager()
{
}
