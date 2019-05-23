#include "GREEN.h"



void GREEN::update(float time, MAP &m)
{
	rect.left += dx * time;
	rect.top += dy * time;
	Collision(m);
	if (dy != 0 || dx != 0)
	{
		if (dy < 0)
		{
			sprite.setTexture(T1);
			switch (life)
			{
			case 3:
				sprite.setTextureRect(IntRect(68, 306, 68, -114));
				break;
			case 2:
				sprite.setTextureRect(IntRect(340, 458, 68, -114));
				break;
			case 1:
				sprite.setTextureRect(IntRect(272, 228, 68, -114));
				break;
			case 0:
				sprite.setTextureRect(IntRect(136, 342, 68, -114));
				dy = 0;
				break;
			default:
				sprite.setTextureRect(IntRect(136, 342, 68, -114));
				dy = 0;
				break;
			}
		}
		if (dy > 0)
		{
			sprite.setTexture(T1);
			switch (life)
			{
			case 3:
				sprite.setTextureRect(IntRect(68, 192, 68, 114));
				break;
			case 2:
				sprite.setTextureRect(IntRect(340, 344, 68, 114));
				break;
			case 1:
				sprite.setTextureRect(IntRect(272, 114, 68, 114));
				break;
			case 0:
				sprite.setTextureRect(IntRect(136, 228, 68, 114));
				dy = 0;
				break;
			default:
				sprite.setTextureRect(IntRect(136, 228, 68, 114));
				dy = 0;
				break;
			}

		}
		if (dx > 0)
		{
			sprite.setTexture(T2);
			switch (life)
			{
			case 3:
				sprite.setTextureRect(IntRect(320, 68, -114, 68));
				break;
			case 2:
				sprite.setTextureRect(IntRect(168, 340, -114, 68));
				break;
			case 1:
				sprite.setTextureRect(IntRect(398, 272, -114, 68));
				break;
			case 0:
				sprite.setTextureRect(IntRect(284, 136, -114, 68));
				dx = 0;
				break;
			default:
				sprite.setTextureRect(IntRect(284, 136, -114, 68));
				dx = 0;
				break;
			}

		}
		if (dx < 0)
		{
			sprite.setTexture(T2);
			switch (life)
			{
			case 3:
				sprite.setTextureRect(IntRect(206, 68, 114, 68));
				break;
			case 2:
				sprite.setTextureRect(IntRect(54, 340, 114, 68));
				break;
			case 1:
				sprite.setTextureRect(IntRect(284, 272, 114, 68));
				break;
			case 0:
				sprite.setTextureRect(IntRect(170, 136, 114, 68));
				dx = 0;
				break;
			default:
				sprite.setTextureRect(IntRect(170, 136, 114, 68));
				dx = 0;
				break;
			}

		}

	}
	sprite.setPosition(rect.left - m.offsetX, rect.top - m.offsetY);
}
