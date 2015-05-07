#pragma once

#include "Action.h"

#include <vector>
#include <list>

#include <SFML/Graphics.hpp>

// History book records all the actions that occur in the scene. also providesa number of lookup tools to search the history
class HistoryBook
{
	std::vector<Action*> eventHistory;	// data structure to hold actions
	
	int time = 0;		// time starts at 0 by default and counts up

	sf::Font font;
	sf::Text eventsText;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	HistoryBook();
	~HistoryBook();

	void ExecuteAction(Action*);	// function to add supplied Action to the history

	void TimeForward();

	//void LookupEvent(std::string);
	int CountEvents() { return eventHistory.size(); }
	int TimeElapsedSince(std::string);
	int TimeElapsedSince(std::string, Stage*);
	int TimeElapsedSinceSubject(std::string, Actor*);
	int TimeSinceStart(){ return time; }
	bool HaventDoneEventBefore(Actor*, std::string);
	bool HaventDoneEventToTargetBefore(Actor*, Actor*, std::string);
	bool HaventDoneEventInLocationBefore(Actor*, Stage*, std::string);
	bool HaventDoneEventSince(Actor*, std::string, int moments);
	bool EventJustHappened(std::string);
	bool EventEverHappened(std::string);
	Action* GetLastEvent() { return eventHistory.back(); }

	bool Draw(sf::RenderWindow &, Stage* s);
	void WriteToFile(int);
};

