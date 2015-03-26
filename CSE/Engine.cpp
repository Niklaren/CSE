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

	Fate->Plan("Begin", Char1, Char2);

	clock.restart();

	stageTexture.loadFromFile("stage.png");
	stageSprite.setTexture(stageTexture);
}

Engine::~Engine()
{

}

void Engine::Operate()
{

	// move time forward
	time = sf::seconds(5.0f) - clock.getElapsedTime();

	GetUserInput();

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

		//  plans execute
		for (int actor_iter(0); actor_iter < MAX_ACTORS; actor_iter++){ // every actor in Actors[]

			// relax actor moods

			// if actor is in the scene? // can do this in ready to execute??

			// for every plan
			for (int plan_iter = actors[actor_iter]->GetNumPlans()-1; plan_iter >= 0; plan_iter--){
				// OK to Execute?()
				if (actors[actor_iter]->GetPlan(plan_iter)->ReadyToExecute()){
					// no? break from loop
					// yes? continue to execute plan

					// store in history books
					historyBook.EventHappened(actors[actor_iter]->GetPlan(plan_iter));

					// execute consequences
					// fate react
					Fate->React();
					// player react ?? can the player not just reacy whenever to the last event?

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
					actors[actor_iter]->DiscardPlan(plan_iter);
				}
			}
		}// next actor
	}

	input.update();
	// check termination conditions

}

void Engine::GetUserInput()
{
	if (input.LMjustReleased()){
		string optionName = "";
		if (menu.OptionClicked(input.MouseX, input.MouseY, optionName)){
			if (optionName == "A" && actionName != ""){
				Protagonist->Plan(actionName,Char1);
				executePlans = true;
				actionName = "";
				menu.Reset();
			}
			else if (optionName == "B" && actionName != ""){
				Protagonist->Plan(actionName,Char2);
				executePlans = true;
				actionName = "";
				menu.Reset();
			}
			else if (optionName == "OK"){
				executePlans = true;
				actionName = "";
				menu.Reset();
			}
			else if (optionName == "Intervene"){
				Protagonist->Plan(optionName, Char1, Char2);
				executePlans = true;
				actionName = "";
				menu.Reset();
			}
			else if (optionName != "OK" && optionName != "A" && optionName != "B"){
				actionName = optionName;
			}
		}
	}
}

void Engine::Redraw(sf::RenderWindow &window)
{
	window.clear();

	window.draw(stageSprite);

	//window.draw xxx
	Char1->Draw(window);
	Char2->Draw(window);

	historyBook.Draw(window);

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
