#include "ENEMY.h"
void ENEMY::Collision(MAP &m)
{
	for (int i = rect.top / 64; i < (rect.top + rect.height) / 64; i++)
		for (int j = rect.left / 64; j < (rect.left + rect.width) / 64; j++)
			if ((m.TileMap[i][j] == 'P') || (m.TileMap[i][j] == '1') || (m.TileMap[i][j] == '0') || (m.TileMap[i][j] == '3') || (m.TileMap[i][j] == '2') ||
				(m.TileMap[i][j] == 'Q') || (m.TileMap[i][j] == 'W') || (m.TileMap[i][j] == 'E') || (m.TileMap[i][j] == 'R') ||
				(m.TileMap[i][j] == 'q') || (m.TileMap[i][j] == 'w') || (m.TileMap[i][j] == 'e') || (m.TileMap[i][j] == 'r') ||
				(m.TileMap[i][j] == 'A') || (m.TileMap[i][j] == 'S') || (m.TileMap[i][j] == 'D') || (m.TileMap[i][j] == 'F') ||
				(m.TileMap[i][j] == 'a') || (m.TileMap[i][j] == 's') || (m.TileMap[i][j] == 'd') || (m.TileMap[i][j] == 'f')
				)
			{
				if (dx > 0)
				{
					rect.left = j * 64 - rect.width;
				}
				if (dx < 0)
				{
					rect.left = j * 64 + 64;
				}
				if (dy > 0)
				{
					rect.top = i * 64 - rect.height;
				}
				if (dy < 0)
				{
					rect.top = i * 64 + 64;
				}
				dy *= -1;
				dx *= -1;
			}
}
void ENEMY::set(Texture &image1, Texture &image2, int x, int y)
{
	T1 = image1;
	T2 = image2;
	sprite.setTexture(image1);
	rect = FloatRect(x, y, 64, 64);
	dx = 0.05;
	life = 3;
}
void ENEMY::set(Texture &image1, Texture &image2, int x, int y, float speedx, float speedy)
{

	T1 = image1;
	T2 = image2;
	sprite.setTexture(image1);
	rect = FloatRect(x, y, 64, 64);
	dx = speedx;
	dy = speedy;
	life = 3;
}


