#pragma once
#include "Action.h"

// wolf reactions to hearing about grandma. makes motivation to eat grandma slighlty more transparent.
class WolfKnowsGrandmaReaction :
	public Action
{
public:
	WolfKnowsGrandmaReaction(Actor* subject_, int moments_);
	WolfKnowsGrandmaReaction();
	~WolfKnowsGrandmaReaction();

	void Init();

	std::string GetSentence();

	virtual void ExecuteConsequences(WorldState*);
	// no emotional reaction
	// use default inclination. since no alternative choices
};