#include "YELLOW.h"



void YELLOW::update(float time, MAP &m)
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
				sprite.setTextureRect(IntRect(68, 420, 68, -114));
				break;
			case 2:
				sprite.setTextureRect(IntRect(340, 228, 68, -114));
				break;
			case 1:
				sprite.setTextureRect(IntRect(204, 458, 68, -114));
				break;
			case 0:
				sprite.setTextureRect(IntRect(136, 114, 68, -114));
				dy = 0;
				break;
			default:
				sprite.setTextureRect(IntRect(136, 114, 68, -114));
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
				sprite.setTextureRect(IntRect(68, 306, 68, 114));
				break;
			case 2:
				sprite.setTextureRect(IntRect(340, 114, 68, 114));
				break;
			case 1:
				sprite.setTextureRect(IntRect(204, 344, 68, 114));
				break;
			case 0:
				sprite.setTextureRect(IntRect(136, 0, 68, 114));
				dy = 0;
				break;
			default:
				sprite.setTextureRect(IntRect(136, 0, 68, 114));
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
				sprite.setTextureRect(IntRect(206, 68, -114, 68));
				break;
			case 2:
				sprite.setTextureRect(IntRect(398, 340, -114, 68));
				break;
			case 1:
				sprite.setTextureRect(IntRect(168, 204, -114, 68));
				break;
			case 0:
				sprite.setTextureRect(IntRect(512, 136, -114, 68));
				dx = 0;
				break;
			default:
				sprite.setTextureRect(IntRect(512, 136, -114, 68));
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
				sprite.setTextureRect(IntRect(92, 68, 114, 68));
				break;
			case 2:
				sprite.setTextureRect(IntRect(284, 340, 114, 68));
				break;
			case 1:
				sprite.setTextureRect(IntRect(54, 204, 114, 68));
				break;
			case 0:
				sprite.setTextureRect(IntRect(398, 136, 114, 68));
				dx = 0;
				break;
			default:
				sprite.setTextureRect(IntRect(398, 136, 114, 68));
				dx = 0;
				break;
			}

		}

	}
	sprite.setPosition(rect.left - m.offsetX, rect.top - m.offsetY);
}