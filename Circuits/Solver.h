#pragma once
#include <vector>
#include "Element.h"

class Solver
{
	float omega;
	//vector<Element> elements;

public:
	Solver(float omega);

	float getOmega();
	//void displaySolution();

	~Solver();
};

