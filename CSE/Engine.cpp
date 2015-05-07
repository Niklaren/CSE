#include "stdafx.h"
#include "Engine.h"


Engine::Engine(Input* input_, int attempt_)
{
	attempt = attempt_;

	input = input_;
	Init();
}

void Engine::Init()
{
	actors.push_back(Fate);
	actors.push_back(Protagonist);
	actors.push_back(Wolf);
	actors.push_back(Lumberjack);
	actors.push_back(Grandma);

	for (unsigned i(0); i < actors.size(); i++){
		actors[i]->SetID(i);
	}

	NPCs.push_back(Wolf);
	NPCs.push_back(Lumberjack);
	NPCs.push_back(Grandma);

	Fate->SetCharacters(Protagonist, Wolf, Lumberjack, Grandma);
	Fate->SetLocations(path, forest, cabin, lodge, offStage);

	Fate->Init();
}

Engine::~Engine()
{

}

// One engine loop
bool Engine::Operate()
{
	
	if (executePlans){
		executePlans = false;
		playerAct = true;
		//clock.restart();

		// the last moment has passed and next moment is occuring.
		for (unsigned actor_iter(0); actor_iter < actors.size(); actor_iter++){
			actors[actor_iter]->TimeForward();
		}
		historyBook.TimeForward();

		// check termination conditions
		Fate->CheckForPlanning();

		// reset 'reaction' world property
		worldstate.WSProperties[WSP_ReactToWorldStateEvent].SetValue(WSE_Invalid);

		//  plans execute
		for (unsigned actor_iter(0); actor_iter < actors.size(); actor_iter++){ // every actor in Actors[]

			// for every plan
			for (int plan_iter = 0; plan_iter < actors[actor_iter]->GetNumPlans(); plan_iter++){
				// OK to Execute?()
				if (actors[actor_iter]->GetPlan(plan_iter)->ReadyToExecute()){
					// no? break from loop
					// yes? continue to execute plan

					// store in history books
					historyBook.ExecuteAction(actors[actor_iter]->GetPlan(plan_iter));
					
					// execute consequences
					historyBook.GetLastEvent()->ExecuteConsequences(&worldstate);
					
					// all witnesses
					for (unsigned i(0); i < NPCs.size(); i++){
						if (historyBook.GetLastEvent()->Get_Location() == NPCs[i]->GetLocation()){
							historyBook.GetLastEvent()->EmotionalReaction(NPCs[i]);
						}
					}

					// test if there is a reaction
					bool reaction;

					// fate react
					reaction = Fate->React();
					
					if (!reaction)
						// action specific reactions
						reaction = historyBook.GetLastEvent()->React();

					// if actor is protagonist and reaction == true
					//	player cant plan next turn
					if (reaction && (actors[actor_iter] == Protagonist))
						playerAct = false;

					// if theplayer just arrived at a new location they can't immediately act
					if ((historyBook.GetLastEvent()->GetVerb() == "Arrive") && (actors[actor_iter] == Protagonist))
						playerAct = false;
				}
			}

			for (int plan_iter = actors[actor_iter]->GetNumPlans(); plan_iter-- > 0;){
				// cleanup plans past their execution time
				if (actors[actor_iter]->GetPlan(plan_iter)->MomentsSinceExecution() >= 0){
					actors[actor_iter]->DiscardPlan(plan_iter);
				}
			}
		}// next actor

		// after all actions have fired
		for (unsigned i(0); i < NPCs.size(); i++){
			if (NPCs[i]->IsGoalComplete())
				NPCs[i]->RemoveCurrentGoal();
			if (NPCs[i]->AcquireGoal() == true) //if we find a more important goal
				NPCs[i]->RePlan();
			if (NPCs[i]->GetNumGoals() == 0){
				//std::cout << "no goals remain " + NPCs[i]->GetName() << std::endl;
			}else if (NPCs[i]->GetNumPlans() == 0){
				//std::cout << "no plan remains " + NPCs[i]->GetName() << std::endl;
				NPCs[i]->RePlan();
			}
			NPCs[i]->CoolMoods();
		}

		// if the player still has plans to execute they can't do more
		if (Protagonist->GetNumPlans() > 0)
			playerAct = false;
		// set the characers the player can interact with
		Protagonist->SetAvailableCharacters(NPCs);
		// reset the choices menu
		Protagonist->menu.Reset(Protagonist->Get_AvailableActions(), Protagonist->Get_AvailableLocations(), Protagonist->Get_AvailableCharacters());
	}
	// loop end

	// look if user has chosen an action
	GetUserInput();

	// write output if and end is reached
	// For testing only
	//if (Fate->ended){
	//	worldstate.WriteToFile(attempt);
	//	historyBook.WriteToFile(attempt);
	//	for (unsigned i(0); i < NPCs.size(); i++){
	//		NPCs[i]->WriteToFile(attempt);
	//	}
	//}

	return Fate->ended;
}

// get the user's choice of action
void Engine::GetUserInput()
{
	string action;
	string target;
	
	// If we do not want the player to act all their options become unavailable
	if (!playerAct)
		Protagonist->menu.AllUnavailable();

	// our player chose an option
	if (Protagonist->menu.HandleMenu(*input, action, target)){
		executePlans = true;	// choice made execute all plans next cycle.

		// special cases for travel. could improve this
		if (action == "Stray Off Path")
			Protagonist->Plan(action, forest);
		else if (action == "Go To Lodge")
			Protagonist->Plan("Travel", lodge);
		else if (action == "Turn Back")
			Protagonist->Plan("Travel", path);
		else if (action == "Continue Forward")
			Protagonist->Plan("Travel", cabin);
		else if (action == "Flee")
			Protagonist->Plan("Flee", cabin);
		else if (action == "Knock Door")
			Protagonist->Plan("Knock Door", Grandma);

		// plan action on target
		if (target == "Wolf")
			Protagonist->Plan(action, Wolf);
		else if (target == "Lumberjack")
			Protagonist->Plan(action, Lumberjack);
		else if (target == "Grandma")
			Protagonist->Plan(action, Grandma);
		// these were removed for special cases. could re-implment later.
		//else if (target == "path")
		//	Protagonist->Plan(action, path);
		//else if (target == "forest")
		//	Protagonist->Plan(action, forest);
		//else if (target == "cabin")
		//	Protagonist->Plan(action, cabin);
		//else if (target == "lodge")
		//	Protagonist->Plan(action, lodge);
		else
			Protagonist->Plan(action);	// normal targetless action

	}
}

// redraw all the elements of the game
void Engine::Redraw(sf::RenderWindow &window)
{
	window.clear();

	//window.draw(stageSprite);
	Protagonist->GetLocation()->Draw(window);

	//window.draw xxx
	for (unsigned i = 0; i < NPCs.size(); i++){
		if (NPCs[i]->GetLocation() == Protagonist->GetLocation())
			NPCs[i]->Draw(window);
	}


	historyBook.Draw(window, Protagonist->GetLocation()); //also pass in player location?

	Protagonist->menu.Draw(window);

	window.display();
}
