#include "stdafx.h"
#include <iostream>
#include "Player.h"

using namespace std;

void Player :: draw()
{
	cout << " ";

	for (int i = 0; i < position; i++)
	{
		cout << "@@";
	}

	cout << "@ª‚ ‚È‚½" << endl;
}