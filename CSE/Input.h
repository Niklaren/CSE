#pragma once

enum Pressed{ just_released = -1, not_pressed, just_pressed, pressed};

class Input
{
private:

public:
	Pressed keys[256];
	Pressed lastLeft, left, right, middle;
	bool MouseMoved;
	float MouseX, MouseY;
	float oldMouseX, oldMouseY;
	float XMoved, YMoved;
	float distanceMoved;
	char distance[20];

	Input();
	~Input();
	void calculatemove();

	bool LMjustPressed() { return left == just_pressed; }
	bool LMjustReleased() { return left == just_released;}


	void handleLMousePressed();
	void handleLMouseReleased();
	void update();
};

