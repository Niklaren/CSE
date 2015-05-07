#pragma once

#include <queue>
#include <vector>

#include "NPC_Actor.h"


// forward declarations
class Node;
class Action;
class Goal;
class NPC_Actor;
class WorldState;
struct WorldStateProperty;

// A Node represents a point in the planners search. Nodes track the running costs, actions performed & the changing goal state
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

// The planner creates a plan to reach the given NPCs supplied goal.
class Planner
{
public:
	Planner();
	~Planner();

	// Only plan is public everything else is hidden. returns true/false and modifies newplan if succesful.
	bool Plan(NPC_Actor*, vector<Action*> &newplan, WorldState, WorldStateProperty);

private:
	bool BuildPaths(Node*, vector<Node*>&, vector<Action*>, WorldState);

	// check or compare conditions to see if the effects of an action get us closer to the goal
	bool Check_Conditions(vector<WorldStateProperty> a, vector<WorldStateProperty> b);	// replaced by compare.
	bool Compare_Conditions(WorldState ws_, vector<WorldStateProperty> a, vector<WorldStateProperty> b);

	// modifies the goal to incorporate the new pre-conditions
	vector<WorldStateProperty> makeNewGoal(vector<WorldStateProperty> oldGoal, vector<WorldStateProperty> actionConditions, vector<WorldStateProperty> actionEffects);
};

