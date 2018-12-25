#include "pch.h"
#include "Solver.h"


Solver::Solver()
{
	elements = new vector<Element*>;
	voltageSources = new vector<Element*>;
}

vector<Element*>* Solver::getElementsPtr()
{
	return elements;
}

vector<Element*>* Solver::getVSsPtr()
{
	return voltageSources;
}


Solver::~Solver()
{
}
