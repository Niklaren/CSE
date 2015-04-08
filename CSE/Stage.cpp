#include "stdafx.h"
#include "Stage.h"


Stage::Stage(std::string imageName, std::string name_)
{
	texture.loadFromFile(imageName);
	sprite.setTexture(texture);

	name = name_;
}

Stage::~Stage()
{
}

void Stage::AddLocationActions(Player_Actor* p)
{
	if (name == "path"){

	}
}

void Stage::RemoveLocationActions(Player_Actor* p)
{

}

bool Stage::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);

	return true;
}
