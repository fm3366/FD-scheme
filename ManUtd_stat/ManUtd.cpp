#include "MAP.h"
#include "PLAYER.h"
#include "ENEMY.h"
#include "YELLOW.h"
#include "GREEN.h"
#include "FORT.h"
#include "JADRO.h"
#include <fstream>
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
	
	/*char buff[40][150];
	std::ifstream fin("D:\\cppstudio.txt");
	for(int k = 0; k<40; k++)
	{
	fin.getline(buff[k], 150); 
	fin.close();
	}
	fin.close();
	for(int t = 0; t< 40; t++)
	{
		for (int y = 0; y < 150; y++)
		{
			m.TileMap[t][y] = buff[t][y];
		}
	}*/
	
	
	

	GameRunning(m);
	return 0;
}