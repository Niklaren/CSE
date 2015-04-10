#include "stdafx.h"
#include "HistoryBook.h"

#include <string>
#include "Actor.h"

HistoryBook::HistoryBook()
{
	if (!font.loadFromFile("Assets/arial.ttf"))
	{	/*error;*/	}
	//eventsText.setFont(font);
	//eventsText.setPosition(sf::Vector2f(50, 260));
	//eventsText.setCharacterSize(24);

	//eventsRect.left = 50;
	//eventsRect.right = 400;
	//eventsRect.top = 250;
	//eventsRect.bottom = 300;

	texture.loadFromFile("Assets/text frame2.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(0, 450));
}


HistoryBook::~HistoryBook()
{
}

void HistoryBook::EventHappened(Action* newestEvent_)
{
	Action* event = newestEvent_;
	eventHistory.push_back(event);
}

void HistoryBook::LookupEvent(string event)
{}

int HistoryBook::TimeElapsedSince(std::string event)
{
	for (unsigned i = eventHistory.size(); i-- > 0;){
		if (eventHistory[i]->GetVerb() == event)
			return eventHistory[i]->MomentsSinceExecution();
	}
	return -1;
}

bool HistoryBook::HaventDoneEventBefore(Actor* a, std::string event)
{
	for (unsigned i = eventHistory.size(); i-- > 0;){
		if ((eventHistory[i]->GetVerb() == event) && (a->GetName() == eventHistory[i]->Get_Subject()->GetName()))
			return false;
	}
	return true;
}

bool HistoryBook::HaventDoneEventSince(Actor*, std::string event, int moments)
{

	return false;
}

bool HistoryBook::EventJustHappened(std::string event)
{
	for (unsigned i = eventHistory.size(); i-- > 0;){
		if (eventHistory[i]->MomentsSinceExecution() == 0 && eventHistory[i]->GetVerb() == event)
			return true;
	}
	return false;
}

bool HistoryBook::Draw(sf::RenderWindow &window, Stage* s)
{
	window.draw(sprite);
	
	float textY = 460;

	for (unsigned i = eventHistory.size(); i-- > 0;){
		if ((eventHistory[i]->MomentsSinceExecution() == 0) && (eventHistory[i]->Get_Location()==s)){
			sf::Text eventsText;
			eventsText.setFont(font);
			eventsText.setPosition(sf::Vector2f(10, textY));
			eventsText.setCharacterSize(20);

			eventsText.setString(eventHistory[i]->GetSentence());
			window.draw(eventsText);
			textY += 30;
		}
	}

	return false;
}

void HistoryBook::TimeForward()
{
	for (unsigned int event_iter(0); event_iter < eventHistory.size(); event_iter++){
		eventHistory[event_iter]->MomentsPass();
	}
	time++;
}