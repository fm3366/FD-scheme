#pragma once
#include "MAP.h"
class FORT
{
public:
	FloatRect rect;
	Sprite sprite;
	FORT(int x, int y, Texture &image)
	{
		sprite.setTexture(image);
		rect = FloatRect(x, y, 128, 128);
		sprite.setTextureRect(IntRect(768, 256, 128, 128));

	}
	void update(MAP &m)
	{
		sprite.setPosition(rect.left - m.offsetX, rect.top - m.offsetY);
	}
};