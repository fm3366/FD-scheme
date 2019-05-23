#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include<math.h>
#include <time.h>
#pragma once

using namespace sf;
class MAP
{
public:
	float offsetX;
	float offsetY;
	int H;
	int W;
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

