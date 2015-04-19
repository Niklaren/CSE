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


class NPC_Actor : public Actor
{
private:	

	BoundedNum selfTraits[5];
	BoundedNum perceivedTraits[5][5]; //can change this to [5][4] and use getID-1 is change_pTrait

	BoundedNum happy;
	BoundedNum angry;

	vector<Goal> goals;
	Goal current;
	Planner* planner;
	WorldState* ws;

	int Replans;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::IntRect actorRect;
	int screenPosx, screenPosy;

public:
	//NPC_Actor(string name, string BitmapFilename, int x, int y, HistoryBook& hb);
	NPC_Actor(string filename, WorldState* w, Planner* p, Stage* l, HistoryBook& hb);
	~NPC_Actor();

	void LoadFromFile(string FileName);

	bool Draw(sf::RenderWindow&);

	virtual bool React();
	//void EmotionalReaction(); // Not sure where this should be located???
	
	void SetWorldState(WorldState* w) { ws = w; }
	void SetPlanner(Planner* p) { planner = p; }

	void AddGoal(Goal);
	bool AcquireGoal();
	void RemoveCurrentGoal();
	void RemoveGoal(string toRemove);
	bool IsGoalComplete();
	int GetNumGoals() { return goals.size(); }

	void ClearPlans();
	void RePlan();
	virtual void Plan(Action*, int );
	virtual void Plan(string verb, int moments, Actor* target);
	virtual void Plan(string action, Stage* l, int moments = 1);
	//virtual void Plan(string action, int m = 1, Actor* t = nullptr, Stage* l = nullptr);

	void CoolMoods();
	void Change_Happy(double);
	void Change_Angry(double);
	double Get_Happy() { return happy.Value(); }
	double Get_Angry() { return angry.Value(); }

	double EmotionalCoefficient() { return (selfTraits[neurotic].Value() + 1); }

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

