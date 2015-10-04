#pragma once

#include "Actor.h"
#include "BoundedNum.h"
#include "Goal.h"
#include "Planner.h"
#include "WorldState.h"

#include <SFML/Graphics.hpp>
#include <list>
#include <vector>

class Planner;
class Goal;
class WorldState;

enum Trait{ open, conscientious, extraverted, agreeable, neurotic, numTraits };
const string s_Traits[5]{ "open", "conscientious", "extraverted", "agreeable", "neurotic" };
enum Chars{ red = 1, wolf, lumberjack, grandma };
const string s_Chars[5]{ "fate", "red", "wolf", "lumberjack", "grandma" };

// subclass of Actor is the NPC Actor
// have to operate autonomously in response to the changing scenarios that could occur.
// Has Personality & moods & perceptions to help decide action
class NPC_Actor : public Actor
{
private:	
	// bounded number for Traits
	BoundedNum selfTraits[5];	// traits use Trait enumeration. currently 5 factor model
	BoundedNum perceivedTraits[5][5];	//perceive every trait of every actor in the scene
	BoundedNum happy;			// if more moods were introduced might like to have array for these too
	BoundedNum angry;			// might alos be worthwhile to perceive moods.

	// NPCs need goals to act towards. they can have multiple goals. but only work towards 1 at any time.
	// they need the planner to figure out how to get a plan that will lead from the world state to their goal
	vector<Goal> goals;
	Goal current;
	Planner* planner;
	WorldState* ws;

	//int Replans;	// we just use this to keep track of how many times agents replan. no operational function

	sf::Texture texture;
	sf::Sprite sprite;
	sf::IntRect actorRect;
	int screenPosx, screenPosy;

	// the neuroticism trait affects how greatly a characters mood will swing
	double EmotionalCoefficient() { return (selfTraits[neurotic].Value() + 1); }

public:
	//NPC_Actor(string name, string BitmapFilename, int x, int y, HistoryBook& hb);
	NPC_Actor(string filename, WorldState* w, Planner* p, Stage* l, HistoryBook& hb);
	~NPC_Actor();

	void LoadFromFile(string FileName);

	bool Draw(sf::RenderWindow&);

	bool React();
	//void EmotionalReaction(); // Not sure where this should be located???
	
	void SetWorldState(WorldState* w) { ws = w; }
	void SetPlanner(Planner* p) { planner = p; }

	// goal related functionality
	void AddGoal(Goal);
	bool AcquireGoal();
	void RemoveCurrentGoal();
	void RemoveGoal(string toRemove);
	bool IsGoalComplete();
	int GetNumGoals() { return goals.size(); }

	void ClearPlans();
	bool RePlan();
	void Plan(Action*, int );
	void Plan(string action, Stage* l, int moments = 1);
	//void Plan(string verb, int moments, Actor* target);
	//void Plan(string action, int m = 1, Actor* t = nullptr, Stage* l = nullptr);

	// change of personality traits
	void CoolMoods();
	void Change_Happy(double);
	void Change_Angry(double);
	double Get_Happy() { return happy.Value(); }
	double Get_Angry() { return angry.Value(); }

	void Change_Conscientious(double);
	void Change_Extraverted(double);
	void Change_Agreeable(double);
	void Change_Neurotic(double);
	void Change_Open(double);
	double Get_Conscientious() { return selfTraits[conscientious].Value(); }
	double Get_Extraverted() { return selfTraits[extraverted].Value(); }
	double Get_Agreeable() { return selfTraits[agreeable].Value(); }
	double Get_Neurotic() { return selfTraits[neurotic].Value(); }
	double Get_Open() { return selfTraits[open].Value(); }

	void Change_pConscientious(double, int);
	void Change_pExtraverted(double, int);
	void Change_pAgreeable(double, int);
	void Change_pNeurotic(double, int);
	void Change_pOpen(double, int);
	double Get_pConscientious(int charID) { return perceivedTraits[conscientious][charID].Value(); }
	double Get_pExtraverted(int charID) { return perceivedTraits[extraverted][charID].Value(); }
	double Get_pAgreeable(int charID) { return perceivedTraits[agreeable][charID].Value(); }
	double Get_pNeurotic(int charID) { return perceivedTraits[neurotic][charID].Value(); }
	double Get_pOpen(int charID) { return perceivedTraits[open][charID].Value(); }

	void WriteToFile(int);

};

