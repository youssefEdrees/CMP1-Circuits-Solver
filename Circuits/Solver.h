#pragma once
#include <vector>
#include "Element.h"

using namespace std;

class Solver
{

	vector<Element> * elements;
	vector<Element> * voltageSources;

public:
	Solver();

	vector<Element> * getElements();
	vector<Element> * getVSs();

	//void displaySolution();

	~Solver();
};

