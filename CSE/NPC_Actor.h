#pragma once

#include "Actor.h"
#include "BoundedNum.h"

#include <SFML/Graphics.hpp>

enum Trait{ open, conscientious, extraverted, agreeable, neurotic };

class NPC_Actor : public Actor
{
	BoundedNum selfTraits[5];

	BoundedNum perceivedTraits[5];

	BoundedNum perceivedPTraits[5];

	BoundedNum happy;
	BoundedNum angry;

	sf::Texture texture;
	sf::Sprite sprite;
	sf::IntRect actorRect;
	int screenPosx, screenPosy;

public:
	NPC_Actor(string name, string BitmapFilename, int x, int y, HistoryBook& hb);
	NPC_Actor(string filename, HistoryBook& hb);
	~NPC_Actor();

	void loadConfig(string FileName);

	bool Draw(sf::RenderWindow&);
	
	virtual void React();
	virtual void Plan(string);
	virtual void Plan(string, Actor*);
	//void EmotionalReaction(); // Not sure where this should be located???

	virtual string GetName() { return name; }

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

