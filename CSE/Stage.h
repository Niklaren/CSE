#pragma once

#include <SFML/Graphics.hpp>

class Actor;

// A location within the scene that characters can move to and act in. Could later expand specific subclasses for specific stages.
class Stage
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	std::string name;
public:
	Stage(std::string image, std::string name);
	~Stage();

	// Add and Remove actions as a result of entering or leaving the area
	void AddLocationActions(Actor* p);
	void RemoveLocationActions(Actor* p);

	bool Draw(sf::RenderWindow &);

	std::string GetName() { return name; }
};

