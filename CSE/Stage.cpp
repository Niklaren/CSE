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

bool Stage::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);

	return true;
}
