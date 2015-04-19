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
	red->AddLocation("forest");
	red->AddLocation("cabin");
	red->AddLocation("lodge");
	red->AddLocation("path");

	// WOLF
	wolf->AddAction("OK");
	//wolf->AddAction("Travel");
	wolf->AddAction("Eat");

	wolf->AddAction("WolfGreetRed", red);
	wolf->AddAction("GiveDirections", red);
	wolf->AddAction("GiveWrongDirections", red);
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
	grandma->AddAction("Greet", red);
	grandma->AddAction("Hug", red);
	grandma->AddAction("Kiss", red);
	grandma->AddAction("Thank", red);

	grandma->AddAction("Reprimand", red);
	grandma->AddAction("Forgive", red);

	// LUMBERJACK
	lumberjack->AddAction("OK");

	lumberjack->AddAction("ChopLog", cabin);
	lumberjack->AddAction("LogOnstump", cabin);
	lumberjack->AddAction("Grablog", cabin);
	//lumberjack->AddAction("Travel");
	lumberjack->AddAction("Greet", red);
	lumberjack->AddAction("GiveDirections", red);
	lumberjack->AddAction("GiveWrongDirections", red);
	lumberjack->AddAction("AgreeEscort", red);
	lumberjack->AddAction("RefuseEscort", red);
}

bool DramaManager::React()
{
	//Action reactingEvent = historyBook->GetLastEvent(); //??

	string reactEvent = historyBook->GetLastEvent()->GetVerb();

	if (reactEvent == "Stray Off Path") // this could? be done in emotional reaction: if(affectingactor == wolf)
	{
		red->RemoveAction("Stray Off Path");

		Goal g1(0.8f,"QueryRed");
		g1.SetWSProperty(WSP_QueryRed, WST_int, 3);
		wolf->AddGoal(g1);

		Goal g2(0.6f,"Eat");
		g2.SetWSProperty(WSP_WolfHungry, WST_bool, false);
		wolf->AddGoal(g2);
	}

	if (reactEvent == "WolfEatGrandma"){
		grandma->MoveLocation(offstage);
	}

	if ((reactEvent == "OpenDoor") && (red->GetLocation() == lodge)){
		if (!ws->WSProperties[WSP_WolfHasLunch].bvalue){
			red->AddAction("Give Food");
		}
		else{
			red->AddAction("Apologize");
		}
		red->AddAction("Greet");
		red->AddAction("Hug");
	}

	if (reactEvent == "WolfEatLunch"){
		wolf->Plan("Travel", offstage);
	}

	if (reactEvent == "WolfEatYou"){
		red->RemoveAllActions();
	}

	if (reactEvent == "SuggestFlowers"){
		red->RemoveAction("Give Food");
	}

	if (reactEvent == "GiveFoodWolf"){
		red->RemoveAction("Flee");
	}

	//if ((wolf->GetLocation() != red->GetLocation()) && (red->GetLocation() == forest)){
	if ((reactEvent == "Travel") && (historyBook->GetLastEvent()->Get_Subject() == wolf) && (red->GetLocation() == forest)){
		red->AddAction("Turn Back");
		red->RemoveAction("Give Food");
		red->RemoveAction("Flee");
		red->RemoveAction("Ask Directions");
		red->RemoveAction("Walk Away");
		if (ws->WSProperties[WSP_WrongDirections].bvalue == true)
			red->AddAction("Continue Forward");
		if (historyBook->EventEverHappened("SuggestFlowers"))
			red->AddAction("Pick Flowers");
	}

	if ((reactEvent == "Arrive") && (historyBook->GetLastEvent()->Get_Subject() == red) && (red->GetLocation() == cabin)){
		Goal g(0.5f, "ChopLumber");
		g.SetWSProperty(WSP_LumberChopped, WST_int, 1);
		lumberjack->AddGoal(g);
	}

	if ((reactEvent == "Arrive") && (historyBook->GetLastEvent()->Get_Subject() == lumberjack) && (lumberjack->GetLocation() == lodge)){
		Goal g(0.5f, "ChopLumber");
		g.SetWSProperty(WSP_LumberChopped, WST_int, 1);
		lumberjack->AddGoal(g);
	}

	if (reactEvent == "AgreeEscort"){
		red->Plan("Travel", lodge);
		lumberjack->ClearPlans();
		lumberjack->Plan("Travel", lodge);
	}

	if (reactEvent == "KillWolf"){
		wolf->MoveLocation(offstage);
		red->RemoveAllActions();
	}

	if ((ws->WSProperties[WSP_QueryRed].ivalue >= 3) && (red->GetLocation() == forest)){
		
	}

	if ((historyBook->EventJustHappened("QueryPurpose")) || (historyBook->EventJustHappened("QueryIdentity")) || (historyBook->EventJustHappened("QueryBasket"))){
		;
	}
	else{
		red->RemoveAction("Answer");
		red->RemoveAction("Ignore");
	}

	if (historyBook->TimeElapsedSince("Arrive", red) > 4){
		red->RemoveAction("Observe");
		red->RemoveAction("Greet");
	}

	if (lumberjack->GetLocation() == wolf->GetLocation()){
		lumberjack->AddAction("KillWolf", wolf);
		Goal g(0.6f, "KillWolf");
		g.SetWSProperty(WSP_WolfDead, WST_bool, true);
		lumberjack->AddGoal(g);
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
		//if (ws->WSProperties[WSP_DeliveryFailed].bvalue == true){
		if (ws->WSProperties[WSP_Forgiven].bvalue || ws->WSProperties[WSP_Reprimanded].bvalue){
			Plan("End");
		}
		if ((ws->WSProperties[WSP_GrandmaEaten].bvalue) && (red->GetLocation() == lodge) && (!ws->WSProperties[WSP_HaveEscort].bvalue)){
			Plan("End");
		}
		if (ws->WSProperties[WSP_WolfDead].bvalue){
			Plan("End");
		}
	}

	if (historyBook->TimeElapsedSince("End") > 0)
	{
		ended = true;
	}
}