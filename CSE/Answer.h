#pragma once
#include "ActionTargeted.h"

// used at the same time as ignore (during wolf interrogation). answer his questions to improve his perception of you.
// answering the question about what you are doing in the woods will give him information about grandma that he can
// use to plan to eat her if that aligns with his inclinations
class Answer :
	public ActionTargeted
{
protected:
	std::string query;
public:
	Answer(Actor* subject_, Actor* object_, int moments_);
	Answer();
	~Answer();
	void Init();

	std::string GetSentence();

	virtual bool GetUsable();

	void ExecuteConsequences(WorldState*);
	void EmotionalReaction(NPC_Actor*);
};