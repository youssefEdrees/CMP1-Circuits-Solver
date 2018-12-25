#pragma once
#include <vector>
#include "Element.h"

using namespace std;

class Solver
{

	vector<Element*> * elements;
	vector<Element*> * voltageSources;

public:
	Solver();

	vector<Element*> * getElementsPtr();
	vector<Element*> * getVSsPtr();

	//void displaySolution();

	~Solver();
};

