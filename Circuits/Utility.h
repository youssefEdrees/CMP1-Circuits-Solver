#pragma once
#include <windows.h>
#include <string>
#include <new>
#include <tchar.h>


using namespace std;

class Utility
{
	Utility();
public:

	static string fileDialog();
	
	~Utility();
};

