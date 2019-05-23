#include "PLAYER.h"
PLAYER::PLAYER(Texture &image, Texture &image2)
{
	sprite.setTexture(image);
	rect = FloatRect(64, 1920, 60, 100);
	dx = dy = 0.1;
	currentFrame = 0;
	HP = 3;
	BF = image2;
	BF1 = image;
	nap = 2;
}
void PLAYER::update(float time, MAP &m)
{
	rect.left += dx * time;
	Collision(0, m);
	rect.top += dy * time;
	Collision(1, m);
	currentFrame += time * 0.005;
	if (dy > 0)
	{
		sprite.setTexture(BF1);
		switch (HP)
		{
		case 3:
			sprite.setTextureRect(IntRect(408, 114, 68, 114));
			break;
		case 2:
			sprite.setTextureRect(IntRect(0, 306, 68, 114));
			break;
		case 1:
			sprite.setTextureRect(IntRect(272, 346, 68, 114));
			break;
		case 0:
			sprite.setTextureRect(IntRect(204, 0, 68, 114));
			break;
		default:
			sprite.setTextureRect(IntRect(408, 114, 68, 114));
			break;
		}
		nap = 3;
	}
	if (dy < 0)
	{
		sprite.setTexture(BF1);
		switch (HP)
		{
		case 3:
			sprite.setTextureRect(IntRect(408, 228, 68, -114));
			break;
		case 2:
			sprite.setTextureRect(IntRect(0, 420, 68, -114));
			break;
		case 1:
			sprite.setTextureRect(IntRect(272, 460, 68, -114));
			break;
		case 0:
			sprite.setTextureRect(IntRect(204, 114, 68, -114));
			break;
		default:
			sprite.setTextureRect(IntRect(408, 114, 68, 114));
			break;
		}
		nap = 1;
	}
	if (dx < 0)
	{
		sprite.setTexture(BF);
		switch (HP)
		{
		case 3:
			sprite.setTextureRect(IntRect(282, 408, 114, 68));
			break;
		case 2:
			sprite.setTextureRect(IntRect(92, 0, 114, 68));
			break;
		case 1:
			sprite.setTextureRect(IntRect(54, 272, 114, 68));
			break;
		case 0:
			sprite.setTextureRect(IntRect(398, 204, 114, 68));
			break;
		default:
			sprite.setTextureRect(IntRect(282, 408, 114, 68));
			break;
		}
		nap = 4;
	}
	if (dx > 0)
	{
		sprite.setTexture(BF);
		switch (HP)
		{
		case 3:
			sprite.setTextureRect(IntRect(396, 408, -114, 68));
			break;
		case 2:
			sprite.setTextureRect(IntRect(206, 0, -114, 68));
			break;
		case 1:
			sprite.setTextureRect(IntRect(168, 272, -114, 68));
			break;
		case 0:
			sprite.setTextureRect(IntRect(512, 204, -114, 68));
			break;
		default:
			sprite.setTextureRect(IntRect(396, 408, -114, 68));
			break;
		}
		nap = 2;
	}
	sprite.setPosition(rect.left - m.offsetX, rect.top - m.offsetY);
	dx = 0;
	dy = 0;
}
void PLAYER::Collision(int num, MAP &m)
{

	for (int i = rect.top / 64; i < (rect.top + rect.height) / 64; i++)
		for (int j = rect.left / 64; j < (rect.left + rect.width) / 64; j++)
		{
			if ((m.TileMap[i][j] == 'P') || (m.TileMap[i][j] == '1') || (m.TileMap[i][j] == '0') || (m.TileMap[i][j] == '3') || (m.TileMap[i][j] == '2') ||
				(m.TileMap[i][j] == 'Q') || (m.TileMap[i][j] == 'W') || (m.TileMap[i][j] == 'E') || (m.TileMap[i][j] == 'R') ||
				(m.TileMap[i][j] == 'q') || (m.TileMap[i][j] == 'w') || (m.TileMap[i][j] == 'e') || (m.TileMap[i][j] == 'r') ||
				(m.TileMap[i][j] == 'A') || (m.TileMap[i][j] == 'S') || (m.TileMap[i][j] == 'D') || (m.TileMap[i][j] == 'F') ||
				(m.TileMap[i][j] == 'a') || (m.TileMap[i][j] == 's') || (m.TileMap[i][j] == 'd') || (m.TileMap[i][j] == 'f')
				)
			{
				if (dy > 0 && num == 1)
				{
					rect.top = i * 64 - rect.height - 10; dy = 0;
					HP = HP - 1;
					Clock clock1;
					clock1.restart();
					float time1 = clock1.getElapsedTime().asMicroseconds();
					while (time1 < 500000)
					{
						time1 = clock1.getElapsedTime().asMicroseconds();
					}
				}
				if (dy < 0 && num == 1)
				{
					rect.top = i * 64 + 64 + 10;  dy = 0;
					HP = HP - 1;
					Clock clock1;
					clock1.restart();
					float time1 = clock1.getElapsedTime().asMicroseconds();
					while (time1 < 500000)
					{
						time1 = clock1.getElapsedTime().asMicroseconds();
					}
				}
				if (dx > 0 && num == 0)
				{
					rect.left = j * 64 - rect.width - 10;
					HP = HP - 1;
					Clock clock1;
					clock1.restart();
					float time1 = clock1.getElapsedTime().asMicroseconds();
					while (time1 < 500000)
					{
						time1 = clock1.getElapsedTime().asMicroseconds();
					}
				}
				if (dx < 0 && num == 0)
				{
					rect.left = j * 64 + 64 + 10;
					HP = HP - 1;
					Clock clock1;
					clock1.restart();
					float time1 = clock1.getElapsedTime().asMicroseconds();
					while (time1 < 500000)
					{
						time1 = clock1.getElapsedTime().asMicroseconds();
					}
				}
			}
			if (m.TileMap[i][j] == 'M')
			{
				m.ZD = 1;
			}
		}
}



