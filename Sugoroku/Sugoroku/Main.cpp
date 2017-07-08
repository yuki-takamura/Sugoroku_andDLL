//testttttttttttttttt

#include <iostream>
#include "DLL_Sugoroku.h"

using namespace std;

int main()
{
	CDLL_Sugoroku sugoroku(6);

	sugoroku.run();

	cout << sugoroku.checkTurn() << "回でゴールしました" << endl;

	cout << "エンターキー入力で終了します" << endl;
	while (getchar() != '\n');//エンターキー入力で次に移る
}
