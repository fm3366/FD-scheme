#include "MAP.h"
#pragma once
using namespace sf;
class ENEMY
{
protected:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	int life;
	Texture T1;
	Texture T2;
public:
	void set(Texture &image1, Texture &image2, int x, int y);
	void set(Texture &image1, Texture &image2, int x, int y, float speedx, float speedy);
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
	int getLife()
	{
		return life;
	}
	void setDX(float a)
	{
		dx = a;
	}
	void setDy(float a)
	{
		dy = a;
	}
	void setRect(FloatRect rect1)
	{
		rect = rect1;
	}
	void setSprite(Sprite sprite1)
	{
		sprite = sprite1;
	}
	void setLife(int a)
	{
		life = a;
	}
	void setTextures(Texture &image1, Texture &image2)
	{
		T1 = image1;
		T2 = image2;
	}
	void Collision(MAP &m);
};
