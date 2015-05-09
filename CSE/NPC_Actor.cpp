#include "stdafx.h"

#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

#include "NPC_Actor.h"


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
			//std::cout << name << std::endl;
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

// Actions will specify if an NPC may react. currently this is when its the object of anothers action. and needs to force replan
// also it may not be necessary to perform the check of being the object. LEAVE FOR NOW though
bool NPC_Actor::React()
{
	// if we we are the object of the last event we have to replan.
	if (historyBook->GetLastEvent()->HasObject()){
		if (historyBook->GetLastEvent()->Get_Object()->GetName() == name){
			Wait();
			if(AcquireGoal()){
				if(RePlan())
					return true;
			}
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

bool NPC_Actor::AcquireGoal() // the most relevant goal becomes the current goal
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

// erase the goal from our goals list and blank the current goal.
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

// remove the specified goal
void NPC_Actor::RemoveGoal(string toRemove)
{
	for (unsigned i = goals.size(); i-- > 0;){
		if (goals[i].GetName() == toRemove){
			if (goals[i] == current){	//if its the current goal remove it from there also
				current.SetWSProperty(WSP_Invalid, WST_Invalid, 0);
				current.SetRelevance(0);
			}
			goals.erase(goals.begin() + i);
		}
	}
}

// if the world state is as we'd like then the goal is met.
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

// something has happened and we need a new plan
bool NPC_Actor::RePlan()
{
	//Replans++;
	
	std::vector<Action*> newplan;

	if (planner->Plan(this, newplan, *ws, current)){
		// scrap our old plan. we have a new one
		ClearPlans();
		// add all the actions of our new plan to our plan data structure
		for (unsigned i = 0; i < newplan.size(); i++){
			//Plan(newplan[i]->GetVerb(), 1+i, current.GetTarget());
			Plan(newplan[i], 1 + i);
		}
	}
	else{
		//no plan
		RemoveCurrentGoal();

		if (AcquireGoal())
			RePlan();
		else
			return false;
	}
	return true;
}

// plan any of our available actions
void NPC_Actor::Plan(Action* action, int moments = 1)
{
	if (action->GetVerb() == "Travel")
		plans.push_back(new Travel(this, moments));
	else if (action->GetVerb() == "WolfEatLunch")
		plans.push_back(new WolfEatLunch(this, moments));
	else if (action->GetVerb() == "WolfKnowsGrandmaReaction")
		plans.push_back(new WolfKnowsGrandmaReaction(this, 1));
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

	// this approach is nice but its preferable to new up an object. we could revisit this later.
	//Action* a = action;
	//a->AddExecutiontime(moments); // adding execution time to the pointed object is not good. could set execution time. still not ideal.
	//plans.push_back(a);
}

// plan travel
void NPC_Actor::Plan(string action, Stage* l, int moments)
{
	// actions that do not have an object;
	if (action == "Travel")
		plans.push_back(new Travel(this, l, moments));
	//else if (action == "Leave")
	//	plans.push_back(new Leave(this, moments));
	else if (action == "Arrive")
		plans.push_back(new Arrive(this, l, moments));

}

bool NPC_Actor::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);
	return true;
}

// moods cool after every moment back towards 0
void NPC_Actor::CoolMoods()
{
	happy.DivideBy(10);
	angry.DivideBy(10);
}

// Change Personalities/Moods
void NPC_Actor::Change_Happy(double d)
{
	d *= EmotionalCoefficient();
	happy.change(d);
	//std::cout << "happy: " << happy.Value() << std::endl;
}

void NPC_Actor::Change_Angry(double d)
{
	d *= EmotionalCoefficient();
	angry.change(d);
	//std::cout << "angry: " << angry.Value() << std::endl;
}

void NPC_Actor::Change_Open(double d)
{
	selfTraits[open].change(d);
	//std::cout << "open: " << selfTraits[open].Value() << std::endl;
}

void NPC_Actor::Change_Conscientious(double d)
{
	selfTraits[conscientious].change(d);
	//std::cout << "conscientious: " << selfTraits[conscientious].Value() << std::endl;
}

void NPC_Actor::Change_Extraverted(double d)
{
	selfTraits[extraverted].change(d);
	//std::cout << "extraverted: " << selfTraits[extraverted].Value() << std::endl;
}

void NPC_Actor::Change_Agreeable(double d)
{
	selfTraits[agreeable].change(d);
	//std::cout << "agreeable: " << selfTraits[agreeable].Value() << std::endl;
}

void NPC_Actor::Change_Neurotic(double d)
{
	selfTraits[neurotic].change(d);
	//std::cout << "neurotic: " << selfTraits[neurotic].Value() << std::endl;
}

void NPC_Actor::Change_pOpen(double d, int charID)
{
	perceivedTraits[open][charID].change(d);
	//std::cout << "Popen: " << perceivedTraits[open][charID].Value() << std::endl;
}

void NPC_Actor::Change_pConscientious(double d, int charID)
{
	perceivedTraits[conscientious][charID].change(d);
	//std::cout << "Pconscientious: " << perceivedTraits[conscientious][charID].Value() << std::endl;
}

void NPC_Actor::Change_pExtraverted(double d, int charID)
{
	perceivedTraits[extraverted][charID].change(d);
	//std::cout << "Pextraverted: " << perceivedTraits[extraverted][charID].Value() << std::endl;
}

void NPC_Actor::Change_pAgreeable(double d, int charID)
{
	perceivedTraits[agreeable][charID].change(d);
	//std::cout << "Pagreeable: " << perceivedTraits[agreeable][charID].Value() << std::endl;
}

void NPC_Actor::Change_pNeurotic(double d, int charID)
{
	perceivedTraits[neurotic][charID].change(d);
	//std::cout << "Pneurotic: " << perceivedTraits[neurotic][charID].Value() << std::endl;
}

void NPC_Actor::WriteToFile(int attempt)
{
	ofstream myfile;
	string file = "Assets/D_" + name + std::to_string(attempt) + ".txt" ;
	myfile.open(file);

	for (unsigned i(0); i < 5; i++){

		if (selfTraits[i].Value() != 0){
			string s = s_Traits[i] + std::to_string(selfTraits[i].Value());
			myfile << s << std::endl;
		}

	}
	
	for (unsigned j(1); j < 5; j++){
		for (unsigned i(0); i < 5; i++){
			if (perceivedTraits[i][j].Value() != 0){
				string s = s_Chars[j] + s_Traits[i] + std::to_string(perceivedTraits[i][j].Value());
				myfile << s << std::endl;
			}

		}
	}

	string s = "Angry" +  std::to_string(angry.Value());
	myfile << s << std::endl;

	s = "happy" + std::to_string(angry.Value());
	myfile << s << std::endl;

	//myfile << "replans: " + std::to_string(Replans) << std::endl;

	myfile.close();
}