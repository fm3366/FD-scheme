#include "MAP.h"
#pragma once
using namespace sf;
class PLAYER {

private:
	int HP;
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	float currentFrame;
	Texture BF;
	Texture BF1;

public:
	int nap;
	PLAYER(Texture &image, Texture &image2);

	int getHP()
	{
		return HP;
	}
	float getDX()
	{
		return dx;
	}
	float getDY()
	{
		return dy;
	}
	FloatRect getrect()
	{
		return rect;
	}
	Sprite getSprite()
	{
		return sprite;
	}
	float getcurrentFrame()
	{
		return currentFrame;
	}
	void setRectLeft(int a)
	{
		rect.left = a;
	}
	void setRect(FloatRect rect1)
	{
		rect = rect1;
	}
	void setDX(float a)
	{
		dx = a;
	}
	void setDy(float a)
	{
		dy = a;
	}
	void setHP(int a)
	{
		HP = a;
	}
	void setSprite(Sprite sprite1)
	{
		sprite = sprite1;
	}
	void setCurrentframe(float a)
	{
		currentFrame = a;
	}
	void update(float time, MAP &m);

	void Collision(int num, MAP &m);


};

