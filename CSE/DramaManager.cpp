#include "stdafx.h"
#include "DramaManager.h"
#include "NPC_Actor.h"
#include "Player_Actor.h"

DramaManager::DramaManager(Stage* s, WorldState* ws_, HistoryBook& hb)
	: Actor("fate", s, hb)
{
	ws = ws_;
}


DramaManager::~DramaManager()
{
}

void DramaManager::SetCharacters(Player_Actor* p, NPC_Actor* w, NPC_Actor* l, NPC_Actor* g)
{
	red = p;
	wolf = w;
	lumberjack = l;
	grandma = g;
}

void DramaManager::SetLocations(Stage* p, Stage* f, Stage* c, Stage* l, Stage* o)
{
	path = p;
	forest = f;
	cabin = c;
	lodge = l;
	offstage = o;
}

void DramaManager::InitLRR()
{
	//YOU
	red->AddAction("Travel");
	red->AddLocation("cabin");

	// WOLF
	wolf->AddAction("OK");
	//wolf->AddAction("Travel");
	wolf->AddAction("Eat");

	wolf->AddAction("WolfGreetRed", red);
	wolf->AddAction("GiveDirections", red);
	wolf->AddAction("QueryIdentity", red);
	wolf->AddAction("QueryPurpose", red);
	wolf->AddAction("QueryBasket", red);

	wolf->AddAction("WolfEat", red);
	wolf->AddAction("WolfEat", grandma);
	wolf->AddAction("WolfEatLunch");
	wolf->AddAction("SuggestFlowers", red);
	wolf->AddAction("RequestEntry", grandma);

	// GRANNY
	grandma->AddAction("OpenDoor");

	// LUMBERJACK
	lumberjack->AddAction("OK");

	lumberjack->AddAction("ChopLog", cabin);
	lumberjack->AddAction("LogOnstump", cabin);
	lumberjack->AddAction("Grablog", cabin);
	//lumberjack->AddAction("Travel");
	lumberjack->AddAction("Greet", red);
	
}

bool DramaManager::React()
{
	//Action reactingEvent = historyBook->GetLastEvent(); //??

	string reactEvent = historyBook->GetLastEvent()->GetVerb();

	if (reactEvent == "Stray Off Path") // this could? be done in emotional reaction: if(affectingactor == wolf)
	{
		red->RemoveAction("Stray Off Path");

		Goal g1(0.8f);
		g1.SetWSProperty(WSP_QueryRed, WST_int, 3);
		wolf->AddGoal(g1);

		Goal g2(0.6f);
		g2.SetWSProperty(WSP_WolfHungry, WST_bool, false);
		wolf->AddGoal(g2);
	}

	if (reactEvent == "WolfEatGrandma"){
		grandma->MoveLocation(offstage);
	}

	if ((reactEvent == "OpenDoor") && (red->GetLocation() == lodge)){
		if (ws->WSProperties[WSP_WolfHasLunch].bvalue){
			red->AddAction("Apologize");
		}
		else{
			red->AddAction("Give Food");
		}
	}

	if ((ws->WSProperties[WSP_QueryRed].ivalue >= 3) && (red->GetLocation() == forest)){
		red->RemoveAction("Ask Directions");
		red->RemoveAction("Walk Away");
	}


	if ((historyBook->EventJustHappened("QueryPurpose")) || (historyBook->EventJustHappened("QueryIdentity")) || (historyBook->EventJustHappened("QueryBasket"))){
		;
	}
	else{
		red->RemoveAction("Answer");
		red->RemoveAction("Ignore");
	}

	if (reactEvent == "WolfEatLunch"){
		wolf->Plan("Travel", offstage);
	}
	
	//if ((wolf->GetLocation() != red->GetLocation()) && (red->GetLocation() == forest)){
	if ((reactEvent == "Travel") && (historyBook->GetLastEvent()->Get_Subject()==wolf) && (red->GetLocation() == forest)){
		red->AddAction("Turn Back");
		red->RemoveAction("Give Food");
		if (ws->WSProperties[WSP_ReactToWorldStateEvent].evalue == WSE_AskDirections)
			red->AddAction("Continue Forward");
	}



	//reactingEvent.CalculateInclination(this);
	return false;
}

void DramaManager::Plan(string action)
{
	if (action == "Begin")
		//plans.push_back(new BeginStory(this, wolf, 0));
		plans.push_back(new BeginLRR(this, red, wolf, lumberjack, grandma, 0));
	else if (action == "Prepare")
		;//plans.push_back(new Prepare(char1, 1));
	else if (action == "End"){
		red->RemoveAllActions();
		red->MoveLocation(offstage);
		plans.push_back(new End(this, 0));
	}
	else{
		// error
	}
}

void DramaManager::Plan(string action, Actor* object)
{
	if (action == "."){

	}
	else{
		// error
	}
}

void DramaManager::Plan(string action, Actor* object_, Actor* extra_)
{
	if (action == "Begin")
	{
		//initialise with a story begin plan
		plans.push_back(new BeginStory(this, object_, 0));
	}
	else if (action == "."){

	}
	else{
		// error
	}
}

void DramaManager::CheckForPlanning()
{
	if (historyBook->TimeSinceStart() == 1)
		Plan("Begin");
	//if (historyBook->TimeSinceStart() == 6)
	//	Plan("Prepare");

	//if ()

	//if ((historyBook->TimeElapsedSince("QueryIdentity")>2) && (historyBook->HaventDoneEventBefore(red,"ReplyIdentity"))
	//if ((historyBook->TimeElapsedSince("QueryPurpose")>2) && (historyBook->HaventDoneEventBefore(red,"ReplyPurpose"))
	//if ((historyBook->TimeElapsedSince("QueryBasket")>2) && (historyBook->HaventDoneEventBefore(red,"ReplyBasket"))
	if (historyBook->HaventDoneEventBefore(this, "End")){
		if (ws->WSProperties[WSP_RedEaten].bvalue == true){
			Plan("End");
		}
		if (ws->WSProperties[WSP_RedHome].bvalue == true){
			Plan("End");
		}
		if (ws->WSProperties[WSP_LunchDelivered].bvalue == true){
			Plan("End");
		}
		if (ws->WSProperties[WSP_DeliveryFailed].bvalue == true){
			Plan("End");
		}
		if ((ws->WSProperties[WSP_GrandmaEaten].bvalue == true) && (red->GetLocation() == lodge)){
			Plan("End");
		}
	}
}