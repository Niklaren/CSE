#pragma once

#include <SFML/Graphics.hpp>

class Actor;

class Stage
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	std::string name;
public:
	Stage(std::string image, std::string name);
	~Stage();

	void AddLocationActions(Actor* p);
	void RemoveLocationActions(Actor* p);

	bool Draw(sf::RenderWindow &);

	std::string GetName() { return name; }
};

