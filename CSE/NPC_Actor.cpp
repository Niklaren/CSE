#include "stdafx.h"

#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

#include "NPC_Actor.h"
//#include "Goal.h"
//#include "Planner.h"
//#include "WorldState.h"
//#include "BoundedNum.h"


NPC_Actor::NPC_Actor(string name, string FileName, int x, int y, HistoryBook& hb)
	: Actor(name, hb)
{
	texture.loadFromFile(FileName);
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f((float)x, (float)y));

	selfTraits[agreeable].setValue(0.0);
	selfTraits[conscientious].setValue(0.0);
	selfTraits[extraverted].setValue(0.0);
	selfTraits[neurotic].setValue(0.0);
	selfTraits[open].setValue(0.0);

	perceivedTraits[agreeable].setValue(0.0);
	perceivedTraits[conscientious].setValue(0.0);
	perceivedTraits[extraverted].setValue(0.0);
	perceivedTraits[neurotic].setValue(-0.0);
	perceivedTraits[open].setValue(0.0);

	perceivedPTraits[agreeable].setValue(0.0);
	perceivedPTraits[conscientious].setValue(0.0);
	perceivedPTraits[extraverted].setValue(0.0);
	perceivedPTraits[neurotic].setValue(-0.0);
	perceivedPTraits[open].setValue(0.0);
}

NPC_Actor::NPC_Actor(string FileName, HistoryBook& hb)
	: Actor(hb)
{
	LoadFromFile(FileName);

}

NPC_Actor::~NPC_Actor()
{
}

void NPC_Actor::LoadFromFile(string FileName)
{
	ifstream fin(FileName);
	string line;
	string imgFileName;
	double dInput;
	int x, y;
	while (getline(fin, line)) {
		istringstream sin(line.substr(line.find("=") + 1));
		if (line.find("name") != -1){
			sin >> name;
			std::cout << name << std::endl;
		}
		else if (line.find("happy") != -1){
			sin >> dInput;
			happy.setValue(dInput);
		}
		else if (line.find("angry") != -1){
			sin >> dInput;
			angry.setValue(dInput);
		}
		else if (line.find("sAgreeable") != -1){
			sin >> dInput;
			selfTraits[agreeable].setValue(dInput);
		}
		else if (line.find("sConscientious") != -1){
			sin >> dInput;
			selfTraits[conscientious].setValue(dInput);
		}
		else if (line.find("sExtraverted") != -1){
			sin >> dInput;
			selfTraits[extraverted].setValue(dInput);
		}
		else if (line.find("sNeurotic") != -1){
			sin >> dInput;
			selfTraits[neurotic].setValue(dInput);
		}
		else if (line.find("sOpen") != -1){
			sin >> dInput;
			selfTraits[open].setValue(dInput);
		}
		else if (line.find("pAgreeable") != -1){
			sin >> dInput;
			perceivedTraits[agreeable].setValue(dInput);
		}
		else if (line.find("pConscientious") != -1){
			sin >> dInput;
			perceivedTraits[conscientious].setValue(dInput);
		}
		else if (line.find("pExtraverted") != -1){
			sin >> dInput;
			perceivedTraits[extraverted].setValue(dInput);
		}
		else if (line.find("pNeurotic") != -1){
			sin >> dInput;
			perceivedTraits[neurotic].setValue(dInput);
		}
		else if (line.find("pOpen") != -1){
			sin >> dInput;
			perceivedTraits[open].setValue(dInput);
		}
		else if (line.find("pPAgreeable") != -1){
			sin >> dInput;
			perceivedPTraits[agreeable].setValue(dInput);
		}
		else if (line.find("pPConscientious") != -1){
			sin >> dInput;
			perceivedPTraits[conscientious].setValue(dInput);
		}
		else if (line.find("pPExtraverted") != -1){
			sin >> dInput;
			perceivedPTraits[extraverted].setValue(dInput);
		}
		else if (line.find("pPNeurotic") != -1){
			sin >> dInput;
			perceivedPTraits[neurotic].setValue(dInput);
		}
		else if (line.find("pPOpen") != -1){
			sin >> dInput;
			perceivedPTraits[open].setValue(dInput);
		}
		else if (line.find("image") != -1){
			sin >> imgFileName;
		}
		else if (line.find("x") != -1){
			sin >> x;
		}
		else if (line.find("y") != -1){
			sin >> y;
		}
	}

	texture.loadFromFile(imgFileName);
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f((float)x, (float)y));
}

void NPC_Actor::AddAction(string action)
{
	if (action == "Insult"){
		Insult* insult_ = new Insult();
		availableActions.push_back(insult_);
	}
	if (action == "Punch"){
		Punch* punch_ = new Punch();
		availableActions.push_back(punch_);
	}
	if (action == "Eat")
		availableActions.push_back(new Eat());
	if (action == "CookGood")
		availableActions.push_back(new CookGood());
	if (action == "CookBad")
		availableActions.push_back(new CookBad());
	if (action == "FetchWater")
		availableActions.push_back(new FetchWater());
	if (action == "FetchWood")
		availableActions.push_back(new FetchWood());
	if (action == "Unpack")
		availableActions.push_back(new Unpack());
	if (action == "BuildStove")
		availableActions.push_back(new BuildStove());
}

void NPC_Actor::RemoveAction(string action)
{
	//std::vector<Action*>::reverse_iterator rit;
	//for (rit = availableActions.rbegin(); rit != availableActions.rend(); ++rit)
	for (unsigned i = availableActions.size(); i-- > 0;)	
	{
		if (availableActions[i]->GetVerb() == action)
			availableActions.erase(availableActions.begin()+i);
	}
}

void NPC_Actor::React()
{
	//Action reactingEvent = historyBook.GetLastEvent();
	
	std::cout << GetName() << std::endl;
	
	historyBook->GetLastEvent()->ExecuteConsequences(ws);
	historyBook->GetLastEvent()->EmotionalReaction(this);
	historyBook->GetLastEvent()->NPC_CalculateInclination(this);
	

	/*if (reactingEvent.GetVerb() == "Begin"){
		BeginStory bs;
		bs.EmotionalReaction(this);
		string NewPlan = bs.CalculateInclination(this);

	}*/
}

void NPC_Actor::AddGoal(Goal newgoal)
{
	goals.emplace_back(newgoal);
}

bool NPC_Actor::AcquireGoal()
{
	bool acquired = false;
	//for (std::vector<Goal>::iterator i = goals.begin(); i!= goals.end(); i++){
	for (unsigned int i = 0; i < goals.size(); i++){
		if (goals[i].CalculateRelevance() > current.CalculateRelevance()){
			current.SetGoal(goals[i]);
			acquired = true;
		}
	}
	return acquired;
}


void NPC_Actor::RemoveCurrentGoal()
{
	for (unsigned i = goals.size(); i-- > 0;){
		if (goals[i] == current){
			goals.erase(goals.begin()+i);
			current.SetWSProperty(WSP_Invalid, WST_Invalid, 0);
			current.SetRelevance(0);
		}
	}
}

void NPC_Actor::ClearPlans()
{
	plans.clear();
}

void NPC_Actor::RePlan()
{
	ClearPlans();
	std::vector<Action*> newplan = planner->Plan(this, *ws, current);
	for (unsigned i = 0; i < newplan.size(); i++){
		Plan(newplan[i]->GetVerb(), 1+i, current.GetTarget());
	}
}

void NPC_Actor::Plan(string action)
{

}

void NPC_Actor::Plan(string action, int moments = 1, Actor* object_ = NULL)
{
	// actions that do not have an object;
	if (action == "OK"){
		OK* ok_ = new OK(this, moments);
		plans.push_back(ok_);
	}
	else if (action == "Eat")
		plans.push_back(new Eat(this, moments));
	else if(action == "CookGood")
		plans.push_back(new CookGood(this, moments));
	else if(action == "CookBad")
		plans.push_back(new CookBad(this, moments));
	else if(action == "FetchWater")
		plans.push_back(new FetchWater(this, moments));
	else if(action == "FetchWood")
		plans.push_back(new FetchWood(this, moments));
	else if(action == "Unpack")
		plans.push_back(new Unpack(this, moments));
	else if(action == "BuildStove")
		plans.push_back(new BuildStove(this, moments));
	else{
		//error
	}


	// actions that have an object;
	if (!object_)
	{
		std::cout << "object null" << std::endl;
		return;
	}

	if (action == "Punch"){
		Punch* punch_ = new Punch(this, object_, moments);
		plans.push_back(punch_);
	}
	else if (action == "Hug"){
		Hug* hug_ = new Hug(this, object_, moments);
		plans.push_back(hug_);
	}
	if (action == "Apologize"){
		Apologize* apologize_ = new Apologize(this, object_, moments);
		plans.push_back(apologize_);
	}
	else if (action == "Insult"){
		Insult* insult_ = new Insult(this, object_, moments);
		plans.push_back(insult_);
	}
	else{
		//error
	}
}

bool NPC_Actor::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);
	return true;
}

void NPC_Actor::Change_Happy(double d)
{
	happy.change(d);
	std::cout << "happy: " << happy.Value() << std::endl;
}

void NPC_Actor::Change_Angry(double d)
{
	angry.change(d);
	std::cout << "angry: " << angry.Value() << std::endl;
}

void NPC_Actor::Change_Open(double d)
{
	selfTraits[open].change(d);
	std::cout << "open: " << selfTraits[open].Value() << std::endl;
}

void NPC_Actor::Change_Conscientious(double d)
{
	selfTraits[conscientious].change(d);
	std::cout << "conscientious: " << selfTraits[conscientious].Value() << std::endl;
}

void NPC_Actor::Change_Extraverted(double d)
{
	selfTraits[extraverted].change(d);
	std::cout << "extraverted: " << selfTraits[extraverted].Value() << std::endl;
}

void NPC_Actor::Change_Agreeable(double d)
{
	selfTraits[agreeable].change(d);
	std::cout << "agreeable: " << selfTraits[agreeable].Value() << std::endl;
}

void NPC_Actor::Change_Neurotic(double d)
{
	selfTraits[neurotic].change(d);
	std::cout << "neurotic: " << selfTraits[neurotic].Value() << std::endl;
}

void NPC_Actor::Change_pOpen(double d)
{
	perceivedTraits[open].change(d);
	std::cout << "Popen: " << perceivedTraits[open].Value() << std::endl;
}

void NPC_Actor::Change_pConscientious(double d)
{
	perceivedTraits[conscientious].change(d);
	std::cout << "Pconscientious: " << perceivedTraits[conscientious].Value() << std::endl;
}

void NPC_Actor::Change_pExtraverted(double d)
{
	perceivedTraits[extraverted].change(d);
	std::cout << "Pextraverted: " << perceivedTraits[extraverted].Value() << std::endl;
}

void NPC_Actor::Change_pAgreeable(double d)
{
	perceivedTraits[agreeable].change(d);
	std::cout << "Pagreeable: " << perceivedTraits[agreeable].Value() << std::endl;
}

void NPC_Actor::Change_pNeurotic(double d)
{
	perceivedTraits[neurotic].change(d);
	std::cout << "Pneurotic: " << perceivedTraits[neurotic].Value() << std::endl;
}

void NPC_Actor::Change_pPOpen(double d)
{
	perceivedPTraits[open].change(d);
	std::cout << "PPopen: " << perceivedPTraits[open].Value() << std::endl;
}

void NPC_Actor::Change_pPConscientious(double d)
{
	perceivedPTraits[conscientious].change(d);
	std::cout << "PPconscientious: " << perceivedPTraits[conscientious].Value() << std::endl;
}

void NPC_Actor::Change_pPExtraverted(double d)
{
	perceivedPTraits[extraverted].change(d);
	std::cout << "PPextraverted: " << perceivedPTraits[extraverted].Value() << std::endl;
}

void NPC_Actor::Change_pPAgreeable(double d)
{
	perceivedPTraits[agreeable].change(d);
	std::cout << "PPagreeable: " << perceivedPTraits[agreeable].Value() << std::endl;
}

void NPC_Actor::Change_pPNeurotic(double d)
{
	perceivedPTraits[neurotic].change(d);
	std::cout << "PPneurotic: " << happy.Value() << std::endl;
}
