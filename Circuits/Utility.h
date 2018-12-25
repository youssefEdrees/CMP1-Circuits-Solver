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
public:

	//static string fileDialog();

	static void load(string path, vector<Element> * elements, vector<Element> * voltageSources);

	~Utility();
};

