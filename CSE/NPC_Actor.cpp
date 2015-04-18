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


//NPC_Actor::NPC_Actor(string name, string FileName, int x, int y, HistoryBook& hb)
//	: Actor(name, hb)
//{
//	texture.loadFromFile(FileName);
//	sprite.setTexture(texture);
//	sprite.setPosition(sf::Vector2f((float)x, (float)y));
//
//	selfTraits[agreeable].setValue(0.0);
//	selfTraits[conscientious].setValue(0.0);
//	selfTraits[extraverted].setValue(0.0);
//	selfTraits[neurotic].setValue(0.0);
//	selfTraits[open].setValue(0.0);
//
//	perceivedTraits[agreeable].setValue(0.0);
//	perceivedTraits[conscientious].setValue(0.0);
//	perceivedTraits[extraverted].setValue(0.0);
//	perceivedTraits[neurotic].setValue(-0.0);
//	perceivedTraits[open].setValue(0.0);
//
//	perceivedPTraits[agreeable].setValue(0.0);
//	perceivedPTraits[conscientious].setValue(0.0);
//	perceivedPTraits[extraverted].setValue(0.0);
//	perceivedPTraits[neurotic].setValue(-0.0);
//	perceivedPTraits[open].setValue(0.0);
//}

NPC_Actor::NPC_Actor(string FileName, WorldState* w, Planner* p, Stage* l, HistoryBook& hb)
	: Actor(hb)
{
	location = l;
	SetPlanner(p);
	SetWorldState(w);
	
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
	int x(0), y(0);
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
		else if (line.find("pRedAgreeable") != -1){
			sin >> dInput;
			perceivedTraits[agreeable][red].setValue(dInput);
		}
		else if (line.find("pRedConscientious") != -1){
			sin >> dInput;
			perceivedTraits[conscientious][red].setValue(dInput);
		}
		else if (line.find("pRedExtraverted") != -1){
			sin >> dInput;
			perceivedTraits[extraverted][red].setValue(dInput);
		}
		else if (line.find("pRedNeurotic") != -1){
			sin >> dInput;
			perceivedTraits[neurotic][red].setValue(dInput);
		}
		else if (line.find("pRedOpen") != -1){
			sin >> dInput;
			perceivedTraits[open][red].setValue(dInput);
		}
		else if (line.find("pWolfAgreeable") != -1){
			sin >> dInput;
			perceivedTraits[agreeable][wolf].setValue(dInput);
		}
		else if (line.find("pWolfConscientious") != -1){
			sin >> dInput;
			perceivedTraits[conscientious][wolf].setValue(dInput);
		}
		else if (line.find("pWolfExtraverted") != -1){
			sin >> dInput;
			perceivedTraits[extraverted][wolf].setValue(dInput);
		}
		else if (line.find("pWolfNeurotic") != -1){
			sin >> dInput;
			perceivedTraits[neurotic][wolf].setValue(dInput);
		}
		else if (line.find("pWolfOpen") != -1){
			sin >> dInput;
			perceivedTraits[open][wolf].setValue(dInput);
		}
		else if (line.find("pLumberjackAgreeable") != -1){
			sin >> dInput;
			perceivedTraits[agreeable][lumberjack].setValue(dInput);
		}
		else if (line.find("pLumberjackConscientious") != -1){
			sin >> dInput;
			perceivedTraits[conscientious][lumberjack].setValue(dInput);
		}
		else if (line.find("pLumberjackExtraverted") != -1){
			sin >> dInput;
			perceivedTraits[extraverted][lumberjack].setValue(dInput);
		}
		else if (line.find("pLumberjackNeurotic") != -1){
			sin >> dInput;
			perceivedTraits[neurotic][lumberjack].setValue(dInput);
		}
		else if (line.find("pLumberjackOpen") != -1){
			sin >> dInput;
			perceivedTraits[open][lumberjack].setValue(dInput);
		}
		else if (line.find("pGrandmaAgreeable") != -1){
			sin >> dInput;
			perceivedTraits[agreeable][grandma].setValue(dInput);
		}
		else if (line.find("pGrandmaConscientious") != -1){
			sin >> dInput;
			perceivedTraits[conscientious][grandma].setValue(dInput);
		}
		else if (line.find("pGrandmaExtraverted") != -1){
			sin >> dInput;
			perceivedTraits[extraverted][grandma].setValue(dInput);
		}
		else if (line.find("pGrandmaNeurotic") != -1){
			sin >> dInput;
			perceivedTraits[neurotic][grandma].setValue(dInput);
		}
		else if (line.find("pGrandmaOpen") != -1){
			sin >> dInput;
			perceivedTraits[open][grandma].setValue(dInput);
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

bool NPC_Actor::React()
{
	//Action reactingEvent = historyBook.GetLastEvent();
	
	std::cout << GetName() + " r" << std::endl;
	
	//historyBook->GetLastEvent()->ExecuteConsequences(ws);
	//historyBook->GetLastEvent()->EmotionalReaction(this);

	// if we we are the object of the last event we have to replan.
	if (historyBook->GetLastEvent()->HasObject()){
		if (historyBook->GetLastEvent()->Get_Object()->GetName() == name){
			//Wait();
			//if (){
				AcquireGoal();
				RePlan();
				return true;
			//}
		}
	}

	return false;
}

void NPC_Actor::AddGoal(Goal newgoal)
{
	for (unsigned i = goals.size(); i-- > 0;){
		if (goals[i].Key == newgoal.Key){
			// if theres already a goal for this property we must overwrite it
			goals.erase(goals.begin()+i);
		}
	}
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
			goals.erase(goals.begin() + i);
			current.SetWSProperty(WSP_Invalid, WST_Invalid, 0);
			current.SetRelevance(0);
		}
	}
}

void NPC_Actor::RemoveGoal(string toRemove)
{
	for (unsigned i = goals.size(); i-- > 0;){
		if (goals[i].GetName() == toRemove){
			if (goals[i] == current){
				current.SetWSProperty(WSP_Invalid, WST_Invalid, 0);
				current.SetRelevance(0);
			}
			goals.erase(goals.begin() + i);
		}
	}
}

bool NPC_Actor::IsGoalComplete()
{
	if (ws->MeetsWorldState(current))
		return true;
	return false;
}

void NPC_Actor::ClearPlans()
{
	plans.clear();
}

void NPC_Actor::RePlan()
{
	ClearPlans();
	
	std::vector<Action*> newplan;

	if (planner->Plan(this, newplan, *ws, current)){
		for (unsigned i = 0; i < newplan.size(); i++){
			//Plan(newplan[i]->GetVerb(), 1+i, current.GetTarget());
			Plan(newplan[i], 1 + i);
		}
	}
	else{
		//no plan
		RemoveCurrentGoal();
	}
}

void NPC_Actor::Plan(Action* action, int moments = 1)
{
	if (action->GetVerb() == "OK")
		plans.push_back(new OK(this, moments));
	else if (action->GetVerb() == "Travel")
		plans.push_back(new Travel(this, moments));
	else if (action->GetVerb() == "WolfEatLunch")
		plans.push_back(new WolfEatLunch(this, moments));
	else{
		//error
	}


	//location specific
	if (action->GetVerb() == "ChopLog")
		plans.push_back(new ChopLog(this, action->Get_Location(), moments));
	else if (action->GetVerb() == "LogOnStump")
		plans.push_back(new LogOnStump(this, action->Get_Location(), moments));
	else if (action->GetVerb() == "GrabLog")
		plans.push_back(new GrabLog(this, action->Get_Location(), moments));
	else if (action->GetVerb() == "OpenDoor")
		plans.push_back(new OpenDoor(this, moments));

	// actions that have an object;
	if (!(action->HasObject()))
	{
		//std::cout << "no object given" << std::endl;
		return;
	}
	else if (action->GetVerb() == "Punch")
		plans.push_back(new Punch(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "Hug")
		plans.push_back(new Hug(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "Greet")
		plans.push_back(new Greet(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "Thank")
		plans.push_back(new Thank(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "Kiss")
		plans.push_back(new Kiss(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "Forgive")
		plans.push_back(new Forgive(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "Reprimand")
		plans.push_back(new Reprimand(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "SuggestFlowers")
		plans.push_back(new SuggestFlowers(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "GiveDirections")
		plans.push_back(new GiveDirections(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "GiveWrongDirections")
		plans.push_back(new GiveWrongDirections(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "WolfGreetRed")
		plans.push_back(new WolfGreetRed(this, action->Get_Object(), moments));
	if (action->GetVerb() == "QueryIdentity")
		plans.push_back(new QueryIdentity(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "QueryPurpose")
		plans.push_back(new QueryPurpose(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "QueryBasket")
		plans.push_back(new QueryBasket(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "WolfEatYou")
		plans.push_back(new WolfEat(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "WolfEatGrandma")
		plans.push_back(new WolfEat(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "RequestEntry")
		plans.push_back(new RequestEntry(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "Intimidate")
		plans.push_back(new Intimidate(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "RefuseEscort")
		plans.push_back(new RefuseEscort(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "AgreeEscort")
		plans.push_back(new AgreeEscort(this, action->Get_Object(), moments));
	else if (action->GetVerb() == "KillWolf")
		plans.push_back(new KillWolf(this, action->Get_Object(), moments));
	else{
		//error
	}

	//Action* a = action;
	//a->AddExecutiontime(moments);
	//plans.push_back(a);
}

void NPC_Actor::Plan(string action, Stage* l, int moments)
{
	// actions that do not have an object;
	if (action == "Travel")
		plans.push_back(new Travel(this, l, moments));
	else if (action == "Leave")
		plans.push_back(new Leave(this, moments));
	else if (action == "Arrive")
		plans.push_back(new Arrive(this, l, moments));

}

void NPC_Actor::Plan(string action, int moments = 1, Actor* object_ = NULL)
{
	// actions that do not have an object;
	if (action == "OK")
		plans.push_back(new OK(this, moments));


	else{
		//error
	}

	// actions that have an object;
	if (!object_)
	{
		std::cout << "object null" << std::endl;
		return;
	}

	if (action == "QueryIdentity")
		plans.push_back(new QueryIdentity(this, object_, moments));
	else if (action == "QueryPurpose")
		plans.push_back(new QueryPurpose(this, object_, moments));
	if (action == "QueryBasket")
		plans.push_back(new QueryBasket(this, object_, moments));
	else if (action == "WolfGreetRed")
		//plans.push_back(new GreetRed(this, object_, moments));
		plans.push_back(new WolfGreetRed(this, object_, moments));
	else if (action == "SuggestFlowers")
		plans.push_back(new SuggestFlowers(this, object_, moments));
	else if (action == "WolfEat")
		plans.push_back(new WolfEat(this, object_, moments));
	else if (action == "RequestEntry")
		plans.push_back(new RequestEntry(this, object_, moments));
	else if (action == "RefuseEscort")
		plans.push_back(new RefuseEscort(this, object_, moments));
	else if (action == "AgreeEscort")
		plans.push_back(new AgreeEscort(this, object_, moments));
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

void NPC_Actor::Change_pOpen(double d, int charID)
{
	perceivedTraits[open][charID].change(d);
	std::cout << "Popen: " << perceivedTraits[open][charID].Value() << std::endl;
}

void NPC_Actor::Change_pConscientious(double d, int charID)
{
	perceivedTraits[conscientious][charID].change(d);
	std::cout << "Pconscientious: " << perceivedTraits[conscientious][charID].Value() << std::endl;
}

void NPC_Actor::Change_pExtraverted(double d, int charID)
{
	perceivedTraits[extraverted][charID].change(d);
	std::cout << "Pextraverted: " << perceivedTraits[extraverted][charID].Value() << std::endl;
}

void NPC_Actor::Change_pAgreeable(double d, int charID)
{
	perceivedTraits[agreeable][charID].change(d);
	std::cout << "Pagreeable: " << perceivedTraits[agreeable][charID].Value() << std::endl;
}

void NPC_Actor::Change_pNeurotic(double d, int charID)
{
	perceivedTraits[neurotic][charID].change(d);
	std::cout << "Pneurotic: " << perceivedTraits[neurotic][charID].Value() << std::endl;
}
