#pragma once
#include <windows.h>
#include <string>
#include <new>
#include <tchar.h>
#include <vector>
#include "Element.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Utility
{
	Utility();

	static void translateLine(string words[],
		float freq,
		Element ** elements,
		int& sizeOfElements,
		Element ** voltageSources,
		int& sizeOfVoltageSources);

public:

	//static string fileDialog();

	static void load(string path, 
		int& numOfNodes, 
		Element ** elements,
		int& sizeOfElements,
		Element ** voltageSources,
		int& sizeOfVoltageSources);

	~Utility();
};

