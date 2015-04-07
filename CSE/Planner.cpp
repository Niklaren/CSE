#include "stdafx.h"
#include "Planner.h"

#include "WorldState.h"
#include "WorldStateProperty.h"
#include "NPC_Actor.h"

//function prototype

Planner::Planner()
{
}

Planner::~Planner()
{
}

std::vector<Action*> Planner::Plan(NPC_Actor* actor, WorldState ws, WorldStateProperty goal)
{
	actor->Get_AvailableActions();
	// reset/refresh variables/contents of available actions?

	// get usable actions
	vector<Action*> usableActions;
	for (signed int action_iter(0); action_iter < actor->Get_NumActions(); action_iter++){
		if (actor->Get_AvailableAction(action_iter)->GetUsable()){
			usableActions.emplace_back(actor->Get_AvailableAction(action_iter));
		}
	}
	
	vector<Node*> solutions;

	vector<WorldStateProperty> goals;
	goals.emplace_back(goal);

	Node* start = new Node(nullptr, 0, goals, nullptr);

	bool success = BuildPaths(start, solutions, usableActions, ws);

	if (!success)
	{
		vector<Action*> noresult;
		return noresult;
	}

	Node* cheapest = solutions.front();
	for (unsigned int i(0); i < solutions.size(); i++)
	{
		if (solutions[i]->runningCost > cheapest->runningCost)
			cheapest = solutions[i];
	}

	vector<Action*> result;
	queue<Action*> qresult;
	Node* n = cheapest;
	while (n != nullptr)
	{
		if (n->action != nullptr)
		{
			result.emplace_back(n->action);
			qresult.push(n->action);
		}
		n = n->parent;
	}

	return result;
}

bool Planner::BuildPaths(Node* parent, vector<Node*>& solutions, vector<Action*> actionPool, WorldState ws)
{
	bool found = false;
	// if goal state != current world state
	if (!(ws.MeetsWorldState(parent->goalState)))
		// for every action
		for (unsigned int index(0); index < actionPool.size(); index++){
			// if actions effect meets an unsatisfied goal condition
			if (Check_Conditions(actionPool[index]->GetEffects(), parent->goalState)){
				// goal is now satisfied (??)
				// goal condition value = action effect value
				// new goal condition = action condition
				vector<WorldStateProperty> newGoal = makeNewGoal(parent->goalState, actionPool[index]->GetConditions(), actionPool[index]->GetEffects());

				//calculate running cost
				float cost = parent->runningCost + 1.0 - actionPool[index]->NPC_CalculateInclination();

				// new node with above
				Node* nextStep = new Node(parent, cost, newGoal, actionPool[index]);

				// build paths
				bool success = BuildPaths(nextStep, solutions, actionPool, ws);

				if (success)
					found = true;
			}
		}
	else
	{
		solutions.emplace_back(parent);
		found = true;
	}
	return found;
}

// function to check if the effect(s) of an action will fulfil at least one of the goal conditions

bool Planner::Check_Conditions(vector<WorldStateProperty> effect, vector<WorldStateProperty> goal)
{
	bool match = false;
	for (unsigned int ie(0); ie < effect.size(); ie++){
		for (unsigned int ig(0); ig < goal.size(); ig++){
			if (effect[ie] == goal[ig])
				match = true;
		}
	}
	return match;
}

vector<WorldStateProperty> Planner::makeNewGoal(vector<WorldStateProperty> oldGoal, vector<WorldStateProperty> actionConditions, vector<WorldStateProperty> actionEffects)
{
	vector<WorldStateProperty> newGoal = oldGoal;

	//remove any goals that were met by effects.
	for (unsigned int iAE(0); iAE < actionEffects.size(); iAE++){
		for (int iG(newGoal.size()-1); iG >= 0; iG--){
			if (newGoal[iG] == actionEffects[iAE]){
				newGoal.erase(newGoal.begin()+iG);
			}
		}
	}

	// add new conditions
	// if actionconditions??
	newGoal.insert(newGoal.end(), actionConditions.begin(), actionConditions.end());

	return newGoal;
}