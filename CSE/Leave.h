//#pragma once

// was going to be part of a leave arrive combo. but travel already handles the leave section.
// both are required to display the message both at the location of leaving and at arriving
// (since messages are only shown to the player if they occur at their location)

//#include "Action.h"
//#include "Stage.h"
//
//class Leave :
//	public Action
//{
//private:
//
//public:
//	Leave(Actor* subject_, int moments_);
//	Leave();
//	~Leave();
//
//	void Init();
//
//	std::string GetSentence();
//
//	void ExecuteConsequences(WorldState*);
//	void EmotionalReaction(NPC_Actor*);
//	float NPC_CalculateInclination();
//
//	virtual bool ReadyToExecute();
//};