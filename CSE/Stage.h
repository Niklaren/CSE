#pragma once

#include <SFML/Graphics.hpp>

class Stage
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	std::string name;
public:
	Stage(std::string image, std::string name);
	~Stage();

	bool Draw(sf::RenderWindow &);

	std::string GetName() { return name; }
};

