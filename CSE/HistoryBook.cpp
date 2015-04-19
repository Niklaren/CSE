#include "stdafx.h"
#include "HistoryBook.h"

#include <string>
#include "fstream"
#include "Actor.h"

HistoryBook::HistoryBook()
{
	if (!font.loadFromFile("Assets/arial.ttf"))
	{	/*error;*/	}
	//eventsText.setFont(font);
	//eventsText.setPosition(sf::Vector2f(50, 260));
	//eventsText.setCharacterSize(24);

	eventsText.setFont(font);
	eventsText.setPosition(sf::Vector2f(10, 460));
	eventsText.setCharacterSize(20);

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

void HistoryBook::ExecuteAction(Action* newestEvent_)
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

int HistoryBook::TimeElapsedSince(std::string event, Actor* a)
{
	for (unsigned i = eventHistory.size(); i-- > 0;){
		if (eventHistory[i]->GetVerb() == event && eventHistory[i]->Get_Subject() == a)
			return eventHistory[i]->MomentsSinceExecution();
	}
	return -1;
}

int HistoryBook::TimeElapsedSince(std::string event, Stage* s)
{
	for (unsigned i = eventHistory.size(); i-- > 0;){
		if (eventHistory[i]->GetVerb() == event && eventHistory[i]->Get_Location() == s)
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

bool HistoryBook::HaventDoneEventToTargetBefore(Actor* a, Actor* b, std::string event){
	for (unsigned i = eventHistory.size(); i-- > 0;){
		if (eventHistory[i]->HasObject()){
			if ((eventHistory[i]->GetVerb() == event) && (a->GetID() == eventHistory[i]->Get_Subject()->GetID()) && (b->GetID() == eventHistory[i]->Get_Object()->GetID()))
				return false;
		}
	}
	return true;
}

bool HistoryBook::HaventDoneEventInLocationBefore(Actor* a, Stage* l, std::string event){
	for (unsigned i = eventHistory.size(); i-- > 0;){
			if ((eventHistory[i]->GetVerb() == event) && (a == eventHistory[i]->Get_Subject()) && (l == eventHistory[i]->Get_Location()))
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

bool HistoryBook::EventEverHappened(std::string event)
{
	for (unsigned i = eventHistory.size(); i-- > 0;){
		if (eventHistory[i]->GetVerb() == event)
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
			//sf::Text eventsText;
			//eventsText.setFont(font);
			eventsText.setPosition(sf::Vector2f(10, textY));
			//eventsText.setCharacterSize(20);
			
			sf::String s = eventHistory[i]->GetSentence();
			unsigned offset(0);
			for (std::size_t pos(0); pos < s.getSize(); ++pos) {
				auto currentChar = s[pos];
				offset++;
				if ((currentChar == ' ') && (offset>50)) {
					s[pos] = '\n';
					offset = 0;
					textY += 30;
				}
				else if (currentChar == '\n') {
					offset = 0;
					textY += 30;
				}
			}

			eventsText.setString(s);
			

			window.draw(eventsText);
			textY += 30;
		}
	}

	return false;
}

void HistoryBook::WriteToFile(int attempt)
{
	ofstream myfile;
	myfile.open("Assets/D_historybook" + std::to_string(attempt)+ ".txt");
	for (unsigned i(0); i < eventHistory.size(); i++){
		myfile << eventHistory[i]->Get_Subject()->GetName() + " ";
		myfile << eventHistory[i]->GetVerb() + " ";
		if (eventHistory[i]->HasObject())
			myfile << eventHistory[i]->Get_Object()->GetName() + " at ";
		myfile << eventHistory[i]->Get_Location()->GetName() + ".    ";
		myfile << eventHistory[i]->GetSentence() << std::endl;
	}
	myfile.close();
}

void HistoryBook::TimeForward()
{
	for (unsigned int event_iter(0); event_iter < eventHistory.size(); event_iter++){
		eventHistory[event_iter]->MomentsPass();
	}
	time++;
}