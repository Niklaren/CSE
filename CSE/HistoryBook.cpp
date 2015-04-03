#include "stdafx.h"
#include "HistoryBook.h"

#include <string>
#include "Actor.h"

HistoryBook::HistoryBook()
{
	if (!font.loadFromFile("arial.ttf"))
	{	/*error;*/	}
	//eventsText.setFont(font);
	//eventsText.setPosition(sf::Vector2f(50, 260));
	//eventsText.setCharacterSize(24);

	//eventsRect.left = 50;
	//eventsRect.right = 400;
	//eventsRect.top = 250;
	//eventsRect.bottom = 300;

	texture.loadFromFile("text frame2.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(0, 250));
}


HistoryBook::~HistoryBook()
{
}

void HistoryBook::EventHappened(Action* newestEvent_)
{
	Action* event = newestEvent_;
	eventHistory.push_back(event);
}

void HistoryBook::LookupEvent(string action)
{}

bool HistoryBook::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);
	
	float textY = 260;

	for (int event_iter = eventHistory.size()-1; event_iter >= 0; event_iter--){
		if (eventHistory[event_iter]->MomentsSinceExecution() == 0){
			sf::Text eventsText;
			eventsText.setFont(font);
			eventsText.setPosition(sf::Vector2f(50, textY));
			eventsText.setCharacterSize(24);

			eventsText.setString(eventHistory[event_iter]->GetSentence());
			window.draw(eventsText);
			textY += 40;
		}
	}

	return false;
}

void HistoryBook::TimeForward()
{
	for (unsigned int event_iter(0); event_iter < eventHistory.size(); event_iter++){
		eventHistory[event_iter]->MomentsPass();
	}
}