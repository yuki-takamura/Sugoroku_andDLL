#include <iostream>
#include "DLL_Sugoroku.h"

using namespace std;

int main()
{
	CDLL_Sugoroku sugoroku(6);

	sugoroku.run();

	cout << sugoroku.checkTurn() << "��ŃS�[�����܂���" << endl;

	cout << "�G���^�[�L�[���͂ŏI�����܂�" << endl;
	while (getchar() != '\n');//�G���^�[�L�[���͂Ŏ��Ɉڂ�
}