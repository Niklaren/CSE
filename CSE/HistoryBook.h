#pragma once

#include "Action.h"

#include <vector>
#include <list>

#include <SFML/Graphics.hpp>

class HistoryBook
{
	std::vector<Action*> eventHistory;
	
	sf::Font font;
	//sf::Text eventsText;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	HistoryBook();
	~HistoryBook();

	void EventHappened(Action*);
	void LookupEvent(std::string);
	int CountEvents();
	int TimeElapsedSince();
	bool HaventDoneEventBefore(std::string);
	bool HaventDoneEventSince(std::string, int moments);
	Action* GetLastEvent() { return eventHistory.back(); } //??

	bool Draw(sf::RenderWindow &);

	void TimeForward();
};

