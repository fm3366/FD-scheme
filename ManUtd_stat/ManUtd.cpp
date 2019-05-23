#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<math.h>
#include <time.h>


using namespace sf;
void menu(RenderWindow & window, bool &exit)
{
	Texture menuTexture1, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("111.png");
	menuTexture3.loadFromFile("333.png");
	menuBackground.loadFromFile("background.jpg");
	Sprite menu1(menuTexture1), menu3(menuTexture3), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 30);
	menu3.setPosition(100, 130);
	menuBg.setPosition(0, 0);
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));

		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window)))
		{
			menu1.setColor(Color::Blue);
			menuNum = 1;
		}
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window)))
		{
			menu3.setColor(Color::Blue);
			menuNum = 3;
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;
			if (menuNum == 3)
			{
				window.close();
				isMenu = false;
				exit = 1;
			}

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu3);

		window.display();
	}
}


class MAP
{
public:
	float offsetX;
	float offsetY;
	int H ;
	int W ;
	int ZD;
	bool isExit;
	String TileMap[40] = {
"Z2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222X",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"1         QWEWEWEWEWEWEWEWEWEWEWEWEWEWEWEWEWEWEWEWEWEWEWEWER                                                                                         3",
"1         asdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsdsXr                                                                                         3",
"1                                                         AF                                                                                         3",
"1                                                      M  qr                                                                                         3",
"1                QWER                                     AF                                                                                         3",
"1    QWEWER      qwer              QWEWEWEWEWEWEWER       qr                                                                                         3",
"1    qwewer      asdf              qwewewewewewewer       AF                                                                                         3",
"1    ASDSDF                        ASDSDSDSDSDZdsdf       qr                                                                                         3",
"1    asdsdf               QWER     qwewewewewer           AF                                                                                         3",
"1                         qwer     ASDSDSDSDSZf           qr                                                                                         3",
"1                         ASDF     asdsdsdsdsf            AF                                                                                         3",
"1                         asdf                            qr                                                                                         3",
"1                                                         AF                                                                                         3",
"1                                    QWEWEWER             qr                                                                                         3",
"1                                    qweweweF             AF                                                                                         3",
"1                                    ASDZdsdf             qr                                                                                         3",
"1                                    qwer                 AF                                                                                         3",
"1                                    asdf                 af                                                                                         3",
"1                                                                                                                                                    3",
"1                                                                                                                                                    3",
"zPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPx",
	};
	MAP()
	{
		offsetX = 0;
		offsetY = 1600;
		H = 40;
		W = 150;
		ZD = 0;
		isExit = 0;
	}


};

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
	PLAYER(Texture &image, Texture &image2)
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
	void update(float time, MAP &m)
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
	void Collision(int num, MAP &m)
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

};
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
	void set(Texture &image1, Texture &image2, int x, int y)
	{
		T1 = image1;
		T2 = image2;
		sprite.setTexture(image1);
		rect = FloatRect(x, y, 64, 64);
		dx = 0.05;
		life = 3;
	}
	void set(Texture &image1, Texture &image2, int x, int y, float speedx, float speedy)
	{

		T1 = image1;
		T2 = image2;
		sprite.setTexture(image1);
		rect = FloatRect(x, y, 64, 64);
		dx = speedx;
		dy = speedy;
		life = 3;
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
	void Collision(MAP &m)
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
};
class GREEN : public ENEMY
{
public:
	void update(float time, MAP &m)
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
};
class YELLOW : public ENEMY
{
public:
	void update(float time, MAP &m)
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
};


void isCollide(PLAYER &P, ENEMY &S)
{
	if (((P.getrect().top - S.getrect().top) * (P.getrect().top - S.getrect().top) + (P.getrect().left - S.getrect().left) * (P.getrect().left - S.getrect().left)) < 32 * 32 * 2)
	{
		P.setHP(P.getHP() - 1);
		if (static_cast<int>(P.getrect().left) % 64 < 32)
		{
			P.setRectLeft(P.getrect().left - 64);
		}
		else
		{
			P.setRectLeft(P.getrect().left + 64);
		}
		Clock clock1;
		clock1.restart();
		float time1 = clock1.getElapsedTime().asMicroseconds();
		while (time1 < 300000)
		{
			time1 = clock1.getElapsedTime().asMicroseconds();
		}

	}
}



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


bool isGameStarted(MAP &m)
{
	RenderWindow window(VideoMode(1440, 960), "Project!");
	menu(window, m.isExit);
	Texture tileSet;
	tileSet.loadFromFile("tiles_sheet.png");
	Texture hero;
	hero.loadFromFile("shipsMiscellaneous_sheet@2.png");
	Texture hero2;
	hero2.loadFromFile("shipsMiscellaneous_sheet@1.png");

	PLAYER Hero(hero, hero2);
	const int N = 8;
	GREEN SH[N];
	SH[0].set(hero, hero2, 320, 2084, 0, 0.2);
	SH[1].set(hero, hero2, 640, 1984, 0, 0.2);
	SH[2].set(hero, hero2, 1280, 1884, 0, 0.2);
	SH[3].set(hero, hero2, 320, 1472, 0.2, 0);
	SH[4].set(hero, hero2, 2176, 1920, 0.2, 0);
	SH[5].set(hero, hero2, 1792, 1472, 0, 0.2);
	SH[6].set(hero, hero2, 3328, 1792, 0.2, 0);
	SH[7].set(hero, hero2, 1856, 1984, 0, 0.2);

	const int K = 5;
	YELLOW SHY[K];
	SHY[0].set(hero, hero2, 3776, 2496, 0, 0.05);
	SHY[1].set(hero, hero2, 1472, 2368, 0, 0.1);
	SHY[2].set(hero, hero2, 3328, 2048, 0.1, 0);
	SHY[3].set(hero, hero2, 128, 1216, 0.1, 0);
	SHY[4].set(hero, hero2, 2176, 1728, 0.1, 0);

	Sprite tile(tileSet);

	FORT A(448, 1600, tileSet);

	Jadro ptr[120];
	int Z = 0;
	Clock clock;
	Clock clock0;
	float time0 = clock0.getElapsedTime().asMicroseconds();
	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 100;

		if (time > 20) time = 20;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
			Hero.setDX(-0.1);

		if (Keyboard::isKeyPressed(Keyboard::Right))
			Hero.setDX(0.1);

		if (Keyboard::isKeyPressed(Keyboard::Up))
			Hero.setDy(-0.1);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			Hero.setDy(0.1);
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			float time10 = clock0.getElapsedTime().asMicroseconds();
			if (time10 - time0 > 500000)
			{
				switch (Hero.nap)
				{
				case 1:
					ptr[Z].set(0.1, 0, Hero.getrect().left + 64, Hero.getrect().top + 32, hero);
					ptr[Z + 1].set(-0.1, 0, Hero.getrect().left, Hero.getrect().top + 32, hero);
					break;
				case 2:
					ptr[Z].set(0, -0.1, Hero.getrect().left + 64, Hero.getrect().top, hero);
					ptr[Z + 1].set(0, 0.1, Hero.getrect().left + 64, Hero.getrect().top + 64, hero);
					break;
				case 3:
					ptr[Z].set(0.1, 0, Hero.getrect().left + 64, Hero.getrect().top + 64, hero);
					ptr[Z + 1].set(-0.1, 0, Hero.getrect().left, Hero.getrect().top + 64, hero);
					break;
				case 4:
					ptr[Z].set(0, 0.1, Hero.getrect().left + 32, Hero.getrect().top + 64, hero);
					ptr[Z + 1].set(0, -0.1, Hero.getrect().left + 32, Hero.getrect().top, hero);
					break;

				default:
					ptr[Z].set(0.1, 0, Hero.getrect().left + 64, Hero.getrect().top + 32, hero);
					break;

				}
				Z = Z + 2;
				std::cout << Z << std::endl;
				std::cout << Hero.getrect().left + 64 << std::endl;
				std::cout << Hero.getrect().top + 32 << std::endl;
				time0 = time10;
			}
		}

		Hero.update(time, m);
		for (int y = 0; y < N; y++)
		{
			SH[y].update(time, m);
		}
		for (int o = 0; o < K; o++)
		{
			SHY[o].update(time, m);
		}
		for (int h = 0; h <= Z; h++)
		{
			ptr[h].update(time, m);
			ptr[h].ATTACK(A);
			for (int Y = 0; Y < N; Y++)
			{
				ptr[h].ATTACK(SH[Y]);
			}
			for (int Y = 0; Y < K; Y++)
			{
				ptr[h].ATTACK(SHY[Y]);
			}
		}

		for (int y = 0; y < N; y++)
		{
			isCollide(Hero, SH[y]);
		}
		for (int y = 0; y < K; y++)
		{
			isCollide(Hero, SHY[y]);
		}
		A.update(m);

		if (Hero.getrect().left > 500) m.offsetX = Hero.getrect().left - 500;
		if (Hero.getrect().top < 2240) m.offsetY = Hero.getrect().top - 600;

		window.clear(Color(107, 140, 255));

		for (int i = 0; i < m.H; i++)
			for (int j = 0; j < m.W; j++)
			{
				if (m.TileMap[i][j] == 'P')
					tile.setTextureRect(IntRect(384, 0, 64, 64));

				if (m.TileMap[i][j] == '1')
					tile.setTextureRect(IntRect(512, 64, 64, 64));

				if (m.TileMap[i][j] == '2')
					tile.setTextureRect(IntRect(384, 192, 64, 64));

				if (m.TileMap[i][j] == '3')
					tile.setTextureRect(IntRect(320, 64, 64, 64));

				if (m.TileMap[i][j] == 'Q')
					tile.setTextureRect(IntRect(320, 0, 64, 64));
				if (m.TileMap[i][j] == 'W')
					tile.setTextureRect(IntRect(384, 0, 64, 64));
				if (m.TileMap[i][j] == 'E')
					tile.setTextureRect(IntRect(448, 0, 64, 64));
				if (m.TileMap[i][j] == 'R')
					tile.setTextureRect(IntRect(512, 0, 64, 64));
				if (m.TileMap[i][j] == 'q')
					tile.setTextureRect(IntRect(320, 64, 64, 64));
				if (m.TileMap[i][j] == 'w')
					tile.setTextureRect(IntRect(384, 64, 64, 64));
				if (m.TileMap[i][j] == 'e')
					tile.setTextureRect(IntRect(448, 64, 64, 64));
				if (m.TileMap[i][j] == 'r')
					tile.setTextureRect(IntRect(512, 64, 64, 64));
				if (m.TileMap[i][j] == 'A')
					tile.setTextureRect(IntRect(320, 128, 64, 64));
				if (m.TileMap[i][j] == 'S')
					tile.setTextureRect(IntRect(384, 128, 64, 64));
				if (m.TileMap[i][j] == 'D')
					tile.setTextureRect(IntRect(448, 128, 64, 64));
				if (m.TileMap[i][j] == 'F')
					tile.setTextureRect(IntRect(512, 128, 64, 64));
				if (m.TileMap[i][j] == 'a')
					tile.setTextureRect(IntRect(320, 192, 64, 64));
				if (m.TileMap[i][j] == 's')
					tile.setTextureRect(IntRect(384, 192, 64, 64));
				if (m.TileMap[i][j] == 'd')
					tile.setTextureRect(IntRect(448, 192, 64, 64));
				if (m.TileMap[i][j] == 'f')
					tile.setTextureRect(IntRect(512, 192, 64, 64));
				if (m.TileMap[i][j] == 'Z')
					tile.setTextureRect(IntRect(192, 128, 64, 64));
				if (m.TileMap[i][j] == 'z')
					tile.setTextureRect(IntRect(192, 192, 64, 64));
				if (m.TileMap[i][j] == 'X')
					tile.setTextureRect(IntRect(256, 128, 64, 64));
				if (m.TileMap[i][j] == 'x')
					tile.setTextureRect(IntRect(256, 192, 64, 64));
				if (m.TileMap[i][j] == 'M')
					tile.setTextureRect(IntRect(384, 256, 64, 64));

				if (m.TileMap[i][j] == ' ')
					continue;

				tile.setPosition(j * 64 - m.offsetX, i * 64 - m.offsetY);
				window.draw(tile);
			}
		window.draw(Hero.getSprite());
		for (int j = 0; j < N; j++)
		{
			window.draw(SH[j].getSprite());
		}
		for (int j = 0; j < K; j++)
		{
			window.draw(SHY[j].getSprite());
		}

		for (int k = 0; k <= Z; k++)
		{
			window.draw(ptr[k].getSprite());
		}
		window.draw(A.sprite);
		if (Keyboard::isKeyPressed(Keyboard::Tab) || Hero.getHP() == -1 || m.ZD == 1)
		{
			m.offsetX = 0;
			m.offsetY = 640;
			m.ZD = 0;
			return true;
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			return false;
		window.display();
	}

}

void GameRunning(MAP &m)
{
	if (isGameStarted(m) && !m.isExit)
	{
		m.offsetX = 0;
		m.offsetY = 640;
		GameRunning(m);
	}
}

int main()
{
	MAP m;
	GameRunning(m);
	return 0;
}