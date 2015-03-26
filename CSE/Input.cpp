#include "stdafx.h"
#include "Input.h"

#include <windows.h>
#include <stdio.h>
#include <math.h>

Input::Input()		//constructor to initialise variables
{
	for (int i = 0; i<256; i++)	//all keys down by default
	{
		keys[i] = not_pressed;
	}

	distanceMoved = 0;
	left, right, middle = not_pressed;
	MouseMoved = not_pressed;
	MouseX, MouseY, oldMouseX, oldMouseY = 0;	//many of these are not rquired for this application
}

Input::~Input()		//constructor to initialise variables
{

}

void Input::calculatemove()	//not used in this application
{
	XMoved = (oldMouseX - MouseX);
	YMoved = (oldMouseY - MouseY);
	if (XMoved < 0){ XMoved *= -1; }
	if (YMoved < 0){ YMoved *= -1; }
	distanceMoved += sqrt((XMoved*XMoved) + (YMoved*YMoved));
}

void Input::handleLMousePressed()
{
	if (left <= not_pressed){
		left = just_pressed;
	}else{
		left = pressed;
	}
}

void Input::handleLMouseReleased()
{
	if (left > not_pressed){
		left = just_released;
	}
	else{
		left = not_pressed;
	}
}

void Input::update()
{
	lastLeft = left;
	if ((lastLeft == just_released) && (left == just_released))
		left = not_pressed;
	if ((lastLeft == just_pressed) && (left == just_pressed))
		left = pressed;
}
