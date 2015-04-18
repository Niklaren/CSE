#pragma once

#include "Action.h"

#include <vector>
#include <list>

#include <SFML/Graphics.hpp>

class HistoryBook
{
	std::vector<Action*> eventHistory;
	
	int time = 0;

	sf::Font font;
	sf::Text eventsText;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	HistoryBook();
	~HistoryBook();

	void ExecuteAction(Action*);

	void LookupEvent(std::string);
	int CountEvents() { return eventHistory.size(); }
	int TimeElapsedSince(std::string);
	int TimeElapsedSince(std::string, Actor*);
	int TimeElapsedSince(std::string, Stage*);
	int TimeSinceStart(){ return time; }
	bool HaventDoneEventBefore(Actor*, std::string);
	bool HaventDoneEventToTargetBefore(Actor*, Actor*, std::string);
	bool HaventDoneEventInLocationBefore(Actor*, Stage*, std::string);
	bool HaventDoneEventSince(Actor*, std::string, int moments);
	bool EventJustHappened(std::string);
	bool EventEverHappened(std::string);
	Action* GetLastEvent() { return eventHistory.back(); }

	bool Draw(sf::RenderWindow &, Stage* s);
	void WriteToFile();

	void TimeForward();
};

