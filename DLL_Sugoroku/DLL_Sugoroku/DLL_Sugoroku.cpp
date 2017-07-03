// DLL_Sugoroku.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DLL_Sugoroku.h"
#include <iostream>

using namespace std;

// This is an example of an exported variable
DLL_SUGOROKU_API int nDLL_Sugoroku=0;

// This is an example of an exported function.
DLL_SUGOROKU_API int fnDLL_Sugoroku(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see DLL_Sugoroku.h for the class definition
CDLL_Sugoroku::CDLL_Sugoroku()
{
    return;
}

int CDLL_Sugoroku::add(int a, int b)
{
	return a + b;
}

void CDLL_Sugoroku::run()
{
	cout << "Hello" << endl;
}
