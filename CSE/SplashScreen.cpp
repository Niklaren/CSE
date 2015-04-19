#include "stdafx.h"
#include "SplashScreen.h"


SplashScreen::SplashScreen(Input* input_)
{
	input = input_;
	
	texture.loadFromFile("Assets/splash.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(0, 0));
}


SplashScreen::~SplashScreen()
{
}

State SplashScreen::Update()
{
	if (input->LMjustReleased()){
		if ((input->MouseX > 350) && (input->MouseX < 450)){	// if in the x bounds
			if ((input->MouseY < 200) && (input->MouseY  > 100)){	// and y bounds
				return game;
			}
		}

		if ((input->MouseX > 350) && (input->MouseX < 450)){	// if in the x bounds
			if ((input->MouseY < 400) && (input->MouseY  > 300)){	// and y bounds
				return close;
			}
		}
	}
	return menu;
}

void SplashScreen::Redraw(sf::RenderWindow &window)
{
	window.clear();

	window.draw(sprite);

	window.display();
}