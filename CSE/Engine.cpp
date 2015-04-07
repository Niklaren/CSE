#include "stdafx.h"
#include "Engine.h"
//#include <map>


Engine::Engine()
{
	//input = input_;


	//Actor *Actors[4] = { Fate, &Protagonist, &Char1, &Char2 };
	actors[0] = Fate;
	actors[1] = Protagonist;
	actors[2] = Char1;
	actors[3] = Char2;

	//Fate->Plan("Begin", Char1, Char2);

	/*Char1->SetPlanner(&planner);
	Char2->SetPlanner(&planner);
	Char1->SetWorldState(&worldstate);
	Char2->SetWorldState(&worldstate);*/

	Char1->AddAction("OK");
	Char1->AddAction("Travel");
	Char1->AddAction("Eat");
	Char1->AddAction("CookGood");
	Char1->AddAction("CookBad");
	Char1->AddAction("BuildStove");
	Char1->AddAction("FetchWater", forest);
	Char1->AddAction("FetchWood");
	Char1->AddAction("Unpack");

	Char1->AddAction("Insult", Protagonist);
	Char1->AddAction("Punch", Protagonist);
	Char1->AddAction("Greet", Protagonist);
	Char1->AddAction("Hug", Protagonist);
	
	Char2->AddAction("OK");

	Char2->AddAction("Insult", Protagonist);
	Char2->AddAction("Punch", Protagonist);
	Char2->AddAction("Greet", Protagonist);
	Char2->AddAction("Hug", Protagonist);

	Protagonist->AddAction("Greet");

	//Goal g(0.5, Char2);
	//g.SetWSProperty(WSP_Punched, WST_bool, true);
	//Char1->AddGoal(g);
	//Char1->AcquireGoal(); //

	//Char1->RePlan();

	clock.restart();

	//stageTexture.loadFromFile("camp.bmp");
	//stageSprite.setTexture(stageTexture);
}

Engine::~Engine()
{

}

void Engine::Operate()
{
	// move time forward
	time = sf::seconds(5.0f) - clock.getElapsedTime();

	//

	//if (time.asSeconds() < 0.0f)
	//{
	//	std::cout << "5" << endl;
	//	executePlans = true;
	//}

	if (executePlans){
		executePlans = false;
		clock.restart();

		// the last moment has passed and next moment is occuring.
		for (int actor_iter(0); actor_iter < MAX_ACTORS; actor_iter++){
			actors[actor_iter]->TimeForward();
		}
		historyBook.TimeForward();

		// check termination conditions
		Fate->CheckForPlanning();

		//  plans execute
		for (int actor_iter(0); actor_iter < MAX_ACTORS; actor_iter++){ // every actor in Actors[]

			// relax actor moods

			// if actor is in the scene? // can do this in ready to execute??

			// for every plan
			for (int plan_iter = 0; plan_iter < actors[actor_iter]->GetNumPlans(); plan_iter++){
				// OK to Execute?()
				if (actors[actor_iter]->GetPlan(plan_iter)->ReadyToExecute()){
					// no? break from loop
					// yes? continue to execute plan

					// store in history books
					historyBook.EventHappened(actors[actor_iter]->GetPlan(plan_iter));

					// execute consequences
					// fate react
					Fate->React();
					// player react ?? can the player not just react whenever to the last event?

					historyBook.GetLastEvent()->React(); // replaces the below
					//// Object react // might some actions not have objects?
					//if (historyBook.GetLastEvent()->HasObject()){
					//	historyBook.GetLastEvent()->GetObject()->React();
					//}
					//// Subject react
					//if (historyBook.GetLastEvent()->HasSubject()){
					//	historyBook.GetLastEvent()->GetSubject()->React();
					//}

					// discard plan
					//actors[actor_iter]->DiscardPlan(plan_iter);
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
		if (Char1->GetNumPlans() == 0)
			Char1->RemoveCurrentGoal();
		if (Char1->GetNumGoals() == 0)
			std::cout << "no goals remain 1" << std::endl;
		if (Char1->AcquireGoal() == true) //if we find a more important goal
			Char1->RePlan();
		actors[2]->GetNumPlans();

		if (Char2->GetNumPlans() == 0)
			Char2->RemoveCurrentGoal();
		if (Char2->GetNumGoals() == 0)
			std::cout << "no goals remain 2" << std::endl;
		if (Char2->AcquireGoal() == true)
			Char2->RePlan();

		menu.Reset(Protagonist->Get_AvailableActions());
	}

	GetUserInput();

	input.update();


}

void Engine::GetUserInput()
{
	string action;
	string target;
	
	if (menu.HandleMenu(input, action, target)){
		executePlans = true;

		if (target == "A")
			Protagonist->Plan(action, Char1);
		else if (target == "B")
			Protagonist->Plan(action, Char2);
		else
			Protagonist->Plan(action);
	}
}

void Engine::Redraw(sf::RenderWindow &window)
{
	window.clear();

	//window.draw(stageSprite);
	Protagonist->GetLocation()->Draw(window);

	//window.draw xxx
	if (Char1->GetLocation() == Protagonist->GetLocation())
		Char1->Draw(window);
	if (Char2->GetLocation() == Protagonist->GetLocation())
		Char2->Draw(window);

	historyBook.Draw(window); //also pass in player location?

	menu.Draw(window);

	window.display();
}

void Engine::HandleInput(InputType inputType)
{
	assert(inputType == LDown || inputType == LUp);
	if (inputType == LDown) input.handleLMousePressed();
	else if (inputType == LUp) input.handleLMouseReleased();
}
void Engine::HandleInput(InputType inputType, float x, float y)
{
		assert(inputType == MouseMove);
		input.MouseX = x;
		input.MouseY = y;
}
