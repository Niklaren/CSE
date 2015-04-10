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
			a->AddAction("Walk Path");
		}
		if (name == "forest"){
			a->AddAction("");
		}
		if (name == "lodge"){
			a->AddAction("Request Entry");
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
			a->AddLocation("path");
		}
		if (name == "forest"){
			a->RemoveAction("");
		}
		if (name == "lodge"){
			a->RemoveAction("Request Entry");
		}
	}
}

bool Stage::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);

	return true;
}
