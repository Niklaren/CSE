#pragma once
#include "ActionTargeted.h"

// give food, to grandma is a successful delivery. to the wolf will sate his hunger. but result in a failed delivery.
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