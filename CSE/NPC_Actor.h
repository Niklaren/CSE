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

enum Trait{ open, conscientious, extraverted, agreeable, neurotic };

class NPC_Actor : public Actor
{
private:	
	BoundedNum selfTraits[5];

	BoundedNum perceivedTraits[5];

	BoundedNum perceivedPTraits[5];

	BoundedNum happy;
	BoundedNum angry;

	vector<Action*> availableActions;
	vector<Goal> goals;
	Goal current;
	Planner* planner;
	WorldState* ws;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::IntRect actorRect;
	int screenPosx, screenPosy;

public:
	NPC_Actor(string name, string BitmapFilename, int x, int y, HistoryBook& hb);
	NPC_Actor(string filename, HistoryBook& hb);
	~NPC_Actor();

	void LoadFromFile(string FileName);
	void AddAction(string ActionName);
	void RemoveAction(string ActionName);

	bool Draw(sf::RenderWindow&);

	virtual void React();
	//void EmotionalReaction(); // Not sure where this should be located???

	
	void SetWorldState(WorldState* w) { ws = w; }
	void SetPlanner(Planner* p) { planner = p; }
	void AddGoal(Goal);
	bool AcquireGoal();
	void RemoveCurrentGoal();
	int GetNumGoals() { return goals.size(); }

	void ClearPlans();
	void RePlan();
	virtual void Plan(string);
	virtual void Plan(string verb, int moments, Actor* target);

	virtual string GetName() { return name; }

	void CoolMoods();
	void Change_Happy(double);
	void Change_Angry(double);
	double Get_Happy() { return happy.Value(); }
	double Get_Angry() { return angry.Value(); }

	double EmotionalCoefficient() { return (selfTraits[neurotic].Value() + 1); }

	vector<Action*> Get_AvailableActions() { return availableActions; }
	int Get_NumActions() { return availableActions.size(); }
	Action* Get_AvailableAction(int i) { return availableActions[i]; }

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

	void Change_pConscientious(double);
	void Change_pExtraverted(double);
	void Change_pAgreeable(double);
	void Change_pNeurotic(double);
	void Change_pOpen(double);
	double Get_pConscientious() { return perceivedTraits[conscientious].Value(); }
	double Get_pExtraverted() { return perceivedTraits[extraverted].Value(); }
	double Get_pAgreeable() { return perceivedTraits[agreeable].Value(); }
	double Get_pNeurotic() { return perceivedTraits[neurotic].Value(); }
	double Get_pOpen() { return perceivedTraits[open].Value(); }

	void Change_pPConscientious(double);
	void Change_pPExtraverted(double);
	void Change_pPAgreeable(double);
	void Change_pPNeurotic(double);
	void Change_pPOpen(double);
	double Get_pPConscientious() { return perceivedPTraits[conscientious].Value(); }
	double Get_pPExtraverted() { return perceivedPTraits[extraverted].Value(); }
	double Get_pPAgreeable() { return perceivedPTraits[agreeable].Value(); }
	double Get_pPNeurotic() { return perceivedPTraits[neurotic].Value(); }
	double Get_pPOpen() { return perceivedPTraits[open].Value(); }
};

