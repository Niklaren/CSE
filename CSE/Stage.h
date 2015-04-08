#pragma once

#include <SFML/Graphics.hpp>

class Player_Actor;

class Stage
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	std::string name;
public:
	Stage(std::string image, std::string name);
	~Stage();

	void AddLocationActions(Player_Actor* p);
	void RemoveLocationActions(Player_Actor* p);

	bool Draw(sf::RenderWindow &);

	std::string GetName() { return name; }
};

