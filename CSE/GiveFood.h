#pragma once
#include "ActionTargeted.h"

class GiveFood :
	public ActionTargeted
{
protected:
	std::string query;
public:
	GiveFood(Actor* subject_, Actor* object_, int moments_);
	GiveFood();
	~GiveFood();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
};