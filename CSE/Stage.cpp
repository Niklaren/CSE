#include "stdafx.h"
#include "Stage.h"
#include "Actor.h"

Stage::Stage(std::string imageName, std::string name_)
{
	texture.loadFromFile(imageName);
	sprite.setTexture(texture);

	name = name_;
}

Stage::~Stage()
{
}

void Stage::AddLocationActions(Actor* a)
{
	if (a->GetName() == "You"){
		if (name == "path"){
			a->AddAction("Go Home");

			/*if (a->GetHistory()->HaventDoneEventBefore(a, "Stray Off Path"))
				a->AddAction("Stray Off Path");*/

			if (a->GetHistory()->HaventDoneEventBefore(a, "WalkPath")){
				a->AddAction("Walk Path");
			}else{
				a->AddAction("Go To Lodge");
			}
		}
		else if (name == "forest"){
			a->AddAction("Observe");
			a->AddAction("Ask Directions");
			a->AddAction("Greet");
			a->AddAction("Walk Away");
		}
		else if (name == "lodge"){
			a->AddAction("Knock Door");
			a->AddAction("Observe");
			if ((!a->GetHistory()->HaventDoneEventBefore(a, "Pick Flowers")) && (a->GetHistory()->HaventDoneEventBefore(a, "Give Flowers"))){
				a->AddAction("Give Flowers");
			}
		}
		else if (name == "cabin"){
			a->AddAction("Observe");
			a->AddAction("Greet");
			a->AddAction("Ask Directions");
			a->AddAction("Request Escort");
			//if (ws->WSP_HaveFlowers == true)
			if ((!a->GetHistory()->HaventDoneEventBefore(a, "Pick Flowers")) && (a->GetHistory()->HaventDoneEventBefore(a, "Give Flowers"))){
				a->AddAction("Give Flowers");
			}
		}
	}
}

void Stage::RemoveLocationActions(Actor* a)
{
	if (a->GetName() == "You"){
		if (name == "path"){
			a->RemoveAction("Go Home");
			a->RemoveAction("Stray Off Path");
			a->RemoveAction("Walk Path");
			a->RemoveAction("Go To Lodge");
			a->AddLocation("path");
		}
		else if (name == "forest"){
			a->RemoveAction("Continue Forward");
			a->RemoveAction("Turn Back");
			a->RemoveAction("Pick Flowers");
			a->RemoveAction("Give Food");
			a->RemoveAction("Flee");
		}
		else if (name == "lodge"){
			a->RemoveAction("Knock Door");
		}
		else if (name == "cabin"){
			a->RemoveAction("Observe");
			a->RemoveAction("Greet");
			a->RemoveAction("Ask Directions");
			a->RemoveAction("Request Escort");
			a->RemoveAction("Go To Lodge");
		}
	}
}

bool Stage::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);

	return true;
}
