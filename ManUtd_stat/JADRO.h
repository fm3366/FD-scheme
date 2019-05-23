#pragma once
#include "ENEMY.h"
#include "FORT.h"
class Jadro
{

public:
	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	bool life;
	Jadro()
	{
		dx = 0;
		dy = 0;
		life = true;
	}
	Sprite getSprite()
	{
		return sprite;
	}
	Jadro(float DX, float DY, int x, int y, Texture &image)
	{
		dx = DX;
		dy = DY;
		sprite.setTexture(image);
		rect = FloatRect(x, y, 10, 10);
		sprite.setTextureRect(IntRect(120, 30, 10, 10));
		life = true;
	}
	void set(float DX, float DY, int x, int y, Texture &image)
	{
		dx = DX;
		dy = DY;
		sprite.setTexture(image);
		rect = FloatRect(x, y, 10, 10);
		sprite.setTextureRect(IntRect(120, 30, 10, 10));
		life = true;
	}
	void update(float time, MAP &m)
	{
		rect.left += dx * time;
		rect.top += dy * time;
		sprite.setPosition(rect.left - m.offsetX, rect.top - m.offsetY);
	}
	void ATTACK(ENEMY &En)
	{
		if (En.getrect().intersects(rect))
		{
			En.setLife(En.getLife() - 1);
			dx = 0;
			dy = 0;
			rect = FloatRect(0, 0, 0, 0);
		}

	}
	void ATTACK(FORT &F)
	{
		if (F.rect.intersects(rect))
		{
			dx = 0;
			dy = 0;
			rect = FloatRect(0, 0, 0, 0);
		}

	}
};
