#pragma once

#include "NPC_Actor.h"
#include "Player_Actor.h"
#include "DramaManager.h"

// Drama Manager specifc to Little Red Riding Hood
// So contains all the characters & locations required by the Story
// Drama Manager is a special Actor with unique privileges and responsibilities in the story
class LRR_DramaManager : public DramaManager
{
private:
	Player_Actor* red;
	NPC_Actor*wolf, *lumberjack, *grandma;
	Stage* path, *forest, *cabin, *lodge, *offstage;

	BeginLRR* begin;
public:
	LRR_DramaManager(Stage* s, WorldState* ws_, HistoryBook& hb);
	~LRR_DramaManager();

	void SetCharacters(Player_Actor* p, NPC_Actor* w, NPC_Actor* l, NPC_Actor* g);
	void SetLocations(Stage* path, Stage* forest, Stage* cabin, Stage* lodge, Stage* offstage);

	void Init();

	bool React();
	void Plan(string);
	void Plan(string, Actor*){}
	void CheckForPlanning();

};

