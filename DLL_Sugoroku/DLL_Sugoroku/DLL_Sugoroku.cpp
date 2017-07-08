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

		while (getchar() != '\n');//�G���^�[�L�[���͂Ŏ��Ɉڂ�

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

	cout << num << "���o�܂���" << endl;

	if (!player.isPausing)
	{
		player.position += num;

		//����}�X�Ɏ~�܂��čs����A�Ăѓ���}�X�Ɏ~�܂��Ă�
		//�����N����Ȃ��悤�ɂ���
		bool canSquareAction = true;

		if (canSquareAction && squareName[player.position] == "F")
		{
			cout << "F�}�X�ɂƂ܂����̂�1�}�X�i�݂܂�" << endl;
			player.position++;
			canSquareAction = false;
		}

		if (canSquareAction && squareName[player.position] == "B")
		{
			cout << "B�}�X�ɂƂ܂����̂�1�}�X�߂�܂�" << endl;
			player.position--;
			canSquareAction = false;
		}

		if (canSquareAction && squareName[player.position] == "P")
		{
			cout << "P�}�X�ɂƂ܂����̂ň��x�݂ł�" << endl;
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
		cout << "���������x�݂Ȃ̂œ����܂���..." << endl;
		player.isPausing = false;
	}
}

void CDLL_Sugoroku::draw()
{
	cout << " S : �X�^�[�g�@ G : �S�[��" << endl;
	cout << " F : 1�}�X�i�ށ@B : 1�}�X�߂�@P : 1��x��" << endl;

	drawMap();
	player.draw();

	cout << "�G���^�[�L�[���͂Ŏ��ɍs���܂�" << endl;
	cout << "------------------------------------------" << endl;
}

void CDLL_Sugoroku::drawMap()
{
	//�}�X�̏㕔
	cout << " ��";

	for (int i = 0; i < SQUARE_NUM - 1;i++)
	{
		cout << "����";
	}

	cout << "����" << endl;

	//�}�X�̒���
	cout << " �� " << squareName[Square::START];
	for (int i = 1; i < SQUARE_NUM - 1; i++)
	{
		cout << "�� " << squareName[i];
	}
	cout << "�� " << squareName[SQUARE_NUM - 1] << "��" << endl;

	//�}�X�̉���
	cout << " ��";

	for (int i = 0; i < SQUARE_NUM - 1; i++)
	{
		cout << "����";
	}

	cout << "����" << endl;
}
