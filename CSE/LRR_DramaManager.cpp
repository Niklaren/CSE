#include "stdafx.h"
#include "LRR_DramaManager.h"
#include "NPC_Actor.h"
#include "Player_Actor.h"

LRR_DramaManager::LRR_DramaManager(Stage* s, WorldState* ws_, HistoryBook& hb)
	: DramaManager( s, ws_, hb)
{

}


LRR_DramaManager::~LRR_DramaManager()
{
}

void LRR_DramaManager::SetCharacters(Player_Actor* p, NPC_Actor* w, NPC_Actor* l, NPC_Actor* g)
{
	red = p;
	wolf = w;
	lumberjack = l;
	grandma = g;
}

void LRR_DramaManager::SetLocations(Stage* p, Stage* f, Stage* c, Stage* l, Stage* o)
{
	path = p;
	forest = f;
	cabin = c;
	lodge = l;
	offstage = o;
}

void LRR_DramaManager::Init()
{
	begin = new BeginLRR(this, red, wolf, lumberjack, grandma, 0);
	begin->path = path;
	begin->forest = forest;
	begin->cabin = cabin;
	begin->lodge = lodge;
	begin->offstage = offstage;
}

// Fate gets to react to events. In many cases this just involves adding or removing actions for the player
// it would be nice to streamline this
bool LRR_DramaManager::React()
{
	string reactEvent = historyBook->GetLastEvent()->GetVerb();

	// when red strays off path wolf will interrogate her and then try to eat.
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

	if (reactEvent == "WolfEatGrandma"){	// if shes dead move offstage. could have this be a consequence of the action instead?
		grandma->MoveLocation(offstage);
	}

	// open up player interaction with grandma after she opens the door for you
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

	// cant ask wold for directions if hes about to kill you
	if (reactEvent == "Intimidate"){
		red->RemoveAction("Ask Directions");
	}

	// wolf moves offstage after eating
	if (reactEvent == "WolfEatLunch"){
		wolf->Plan("Travel", offstage);
		if (red->GetLocation() == wolf->GetLocation())
		red->RemoveAction("Ask Directions");
	}

	if (reactEvent == "WolfEatYou"){
		red->RemoveAllActions();
	}

	// hes decided to eat grandma. cant give him food anymore
	if (reactEvent == "SuggestFlowers"){
		red->RemoveAction("Give Food");
	}

	// chose to givefood rather than flee.
	if (reactEvent == "GiveFoodWolf"){
		red->RemoveAction("Flee");
	}

	// when the wolf leaves forest, player options change
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

	// give lumberjack lumber chop goal
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

	// force lumberjack to escort. this could be done better (planning travel) 
	if (reactEvent == "AgreeEscort"){
		red->Plan("Travel", lodge);
		lumberjack->ClearPlans();
		lumberjack->Plan("Travel", lodge);
	}

	// wolf killed. move offstage. could be consquence of killwolf action probably.
	if (reactEvent == "KillWolf"){
		wolf->MoveLocation(offstage);
		red->RemoveAllActions();
	}

	// query - answer/ignore section
	if ((historyBook->EventJustHappened("QueryPurpose")) || (historyBook->EventJustHappened("QueryIdentity")) || (historyBook->EventJustHappened("QueryBasket"))){
		;
	}
	else{
		red->RemoveAction("Answer");
		red->RemoveAction("Ignore");
	}

	// 
	if (historyBook->EventJustHappened("GiveDirections")){
		red->AddAction("Thank");
	}
	else{
		red->RemoveAction("Thank");
	}

	// doesn't make sense to greet a character after such a time. (same with observe) remove them to focus player choice.
	if (historyBook->TimeElapsedSinceSubject("Arrive", red) > 4){
		red->RemoveAction("Observe");
		red->RemoveAction("Greet");
	}

	// inject goal for lumberjack to kill wolf.
	if (lumberjack->GetLocation() == wolf->GetLocation()){
		lumberjack->AddAction("KillWolf", wolf);
		Goal g(0.6f, "KillWolf");
		g.SetWSProperty(WSP_WolfDead, WST_bool, true);
		lumberjack->AddGoal(g);
	}


	return false;	// drama manager reactions dont need to affect other characters in the same way. so just return false for now.
	// certain reaction might warrant a return true, if they would require the other actors & player to respond to an event.
}

// Plan begin or end actions. could be more if we wanted to directthe story to a greater degree
void LRR_DramaManager::Plan(string action)
{
	if (action == "Begin")
		plans.push_back(begin);
	else if (action == "End"){
		red->RemoveAllActions();

		red->MoveLocation(offstage);
		plans.push_back(new End(this, 0));
	}
	else{
		// error
	}
}

// check if we need to perform the begin or end events
void LRR_DramaManager::CheckForPlanning()
{
	// begin
	if (historyBook->TimeSinceStart() == 1)
		Plan("Begin");

	// check for end states
	if (historyBook->HaventDoneEventBefore(this, "End")){
		if (ws->WSProperties[WSP_RedEaten].bvalue == true){ // if player eaten
			Plan("End");
		}
		if (ws->WSProperties[WSP_RedHome].bvalue == true){ // if player went home
			Plan("End");
		}
		if (ws->WSProperties[WSP_LunchDelivered].bvalue == true){// if delivery success
			Plan("End");
		}
		//if (ws->WSProperties[WSP_DeliveryFailed].bvalue == true){
		if (ws->WSProperties[WSP_Forgiven].bvalue || ws->WSProperties[WSP_Reprimanded].bvalue){ //if delovery failed.
			Plan("End");
		}
		//if player sees grandma has been eaten
		if ((ws->WSProperties[WSP_GrandmaEaten].bvalue) && (red->GetLocation() == lodge) && (!ws->WSProperties[WSP_HaveEscort].bvalue)){
			Plan("End");
		}
		if (ws->WSProperties[WSP_WolfDead].bvalue){ //if lumberjack slays the wolf
			Plan("End");
		}
	}

	if (historyBook->TimeElapsedSince("End") > 0)
	{
		ended = true;	// set ended true for exit condition
	}
}