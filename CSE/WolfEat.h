#pragma once
#include "ActionTargeted.h"

// wolf eats you/grandma.
// depends on how you treat him how inclined he will be.
// can only eat grandma if you mentioned her previously.
class WolfEat :
	public ActionTargeted
{
public:
	WolfEat(Actor* subject_, Actor* object_, int moments_);
	WolfEat();
	~WolfEat();

	void Init();

	std::string GetSentence();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
	double NPC_CalculateInclination();
};