#include <iostream>
#include "DLL_Sugoroku.h"

using namespace std;

int main()
{
	CDLL_Sugoroku sugoroku;

	cout << sugoroku.add(2, 3) << endl;

	sugoroku.run();

	return 0;
}