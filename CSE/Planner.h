#pragma once

#include <queue>
#include <vector>

//#include "Action.h"
//#include "WorldStateProperty.h"
//#include "WorldState.h"
#include "NPC_Actor.h"


// forward declaration
class Node;
class Action;
class Goal; //?
class NPC_Actor;
class WorldState;
struct WorldStateProperty;

class Node
{
public: 
	Node* parent;
	float runningCost;
	vector<WorldStateProperty> goalState; // list of WSPs
	Action* action;

	Node(Node* parent_, float runningCost_, vector<WorldStateProperty> goal_, Action* action_) {
		parent = parent_;
		runningCost = runningCost_;
		goalState = goal_;
		action = action_;
	}
};

class Planner
{
public:
	Planner();
	~Planner();

	//std::vector<Action*> Plan(NPC_Actor*, /*available actions,*/ WorldState, WorldStateProperty);
	bool Plan(NPC_Actor*, vector<Action*> &newplan, WorldState, WorldStateProperty);

private:
	bool BuildPaths(Node*, vector<Node*>&, vector<Action*>, WorldState);
	bool IsInState(); // may not be necessary if world state class can check equality
	bool IsCloser();

	bool Check_Conditions(vector<WorldStateProperty> a, vector<WorldStateProperty> b);
	bool Compare_Conditions(WorldState ws_, vector<WorldStateProperty> a, vector<WorldStateProperty> b);
	vector<WorldStateProperty> makeNewGoal(vector<WorldStateProperty> oldGoal, vector<WorldStateProperty> actionConditions, vector<WorldStateProperty> actionEffects);
};

