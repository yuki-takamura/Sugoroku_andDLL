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

// This class is exported from the DLL_Sugoroku.dll
class DLL_SUGOROKU_API CDLL_Sugoroku {
public:
	CDLL_Sugoroku(void);
	// TODO: add your methods here.
	int Add(int a, int b);
};

extern DLL_SUGOROKU_API int nDLL_Sugoroku;

DLL_SUGOROKU_API int fnDLL_Sugoroku(void);
