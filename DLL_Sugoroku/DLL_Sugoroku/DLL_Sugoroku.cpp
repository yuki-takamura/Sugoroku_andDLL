// DLL_Sugoroku.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DLL_Sugoroku.h"
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

// This is the constructor of a class that has been exported.
// see DLL_Sugoroku.h for the class definition
CDLL_Sugoroku::CDLL_Sugoroku(int diceNum)
{
	this->diceNum = diceNum;
	srand((unsigned)time(NULL));
}

void CDLL_Sugoroku::run()
{
	initialize();

	bool isFirstDraw = true;

	while (true)
	{
		if(!isFirstDraw)
			update();
		draw();

		while (getchar() != '\n');//エンターキー入力で次に移る

		if(turn < MAX_TURN)
			turn++;

		if (isFirstDraw)
			isFirstDraw = false;

		if (isGameClear)
			break;
	}
}

void CDLL_Sugoroku::initialize()
{
	player.isPausing = false;
	player.position = 0;
	isGameClear = false;
	turn = 1;

	squareName[Square::START] = "S";

	for (int i = 1; i < SQUARE_NUM - 1; i++)
	{
		switch (rand() % 4 + 2)
		{

		case Square::BACK:
			squareName[i] = "B";
			break;

		case Square::FORWARD :
			squareName[i] = "F";
			break;

		case Square::PASS:
			squareName[i] = "P";
			break;

		case Square::NORMAL:
			squareName[i] = " ";
			break;
		}
	}

	squareName[SQUARE_NUM - 1] = "G";
}

void CDLL_Sugoroku::update()
{
	int num = rand() % diceNum + 1;

	cout << num << "が出ました" << endl;

	if (!player.isPausing)
	{
		player.position += num;

		//特殊マスに止まって行動後、再び特殊マスに止まっても
		//何も起こらないようにする
		bool canSquareAction = true;

		if (canSquareAction && squareName[player.position] == "F")
		{
			cout << "Fマスにとまったので1マス進みます" << endl;
			player.position++;
			canSquareAction = false;
		}

		if (canSquareAction && squareName[player.position] == "B")
		{
			cout << "Bマスにとまったので1マス戻ります" << endl;
			player.position--;
			canSquareAction = false;
		}

		if (canSquareAction && squareName[player.position] == "P")
		{
			cout << "Pマスにとまったので一回休みです" << endl;
			canSquareAction = false;
			player.isPausing = true;
		}

		if (player.position >= SQUARE_NUM - 1)
		{
			player.position = SQUARE_NUM - 1;
			isGameClear = true;
		}
	}
	else
	{
		cout << "しかし一回休みなので動きません..." << endl;
		player.isPausing = false;
	}
}

void CDLL_Sugoroku::draw()
{
	cout << " S : スタート　 G : ゴール" << endl;
	cout << " F : 1マス進む　B : 1マス戻る　P : 1回休み" << endl;

	drawMap();
	player.draw();

	cout << "エンターキー入力で次に行きます" << endl;
	cout << "------------------------------------------" << endl;
}

void CDLL_Sugoroku::drawMap()
{
	//マスの上部
	cout << " ┏";

	for (int i = 0; i < SQUARE_NUM - 1;i++)
	{
		cout << "━┳";
	}

	cout << "━┓" << endl;

	//マスの中部
	cout << " ┃ " << squareName[Square::START];
	for (int i = 1; i < SQUARE_NUM - 1; i++)
	{
		cout << "┃ " << squareName[i];
	}
	cout << "┃ " << squareName[SQUARE_NUM - 1] << "┃" << endl;

	//マスの下部
	cout << " ┗";

	for (int i = 0; i < SQUARE_NUM - 1; i++)
	{
		cout << "━┻";
	}

	cout << "━┛" << endl;
}
