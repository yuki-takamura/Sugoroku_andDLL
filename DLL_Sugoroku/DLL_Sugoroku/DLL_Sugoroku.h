// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DLL_SUGOROKU_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DLL_SUGOROKU_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLL_SUGOROKU_EXPORTS
#define DLL_SUGOROKU_API __declspec(dllexport)
#else
#define DLL_SUGOROKU_API __declspec(dllimport)
#endif

#include <iostream>
#include <string>
#include "ConstantMacro.h"
#include "Player.h"

// This class is exported from the DLL_Sugoroku.dll
class DLL_SUGOROKU_API CDLL_Sugoroku
{
public:
	CDLL_Sugoroku(int diceNum);
	// TODO: add your methods here.
	int checkTurn() { return turn - 2; }
	void run();

private :
	bool isGameClear;
	int diceNum;
	int turn;
	std::string squareName[SQUARE_NUM];
	Player player;
	
	
	void initialize();
	void update();
	void draw();
	void drawMap();
};
