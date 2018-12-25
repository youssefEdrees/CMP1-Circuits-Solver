#include "pch.h"
#include "Solver.h"


Solver::Solver()
{
	elements = new vector<Element>;
	voltageSources = new vector<Element>;
}

vector<Element>* Solver::getElements()
{
	return elements;
}

vector<Element>* Solver::getVSs()
{
	return voltageSources;
}


Solver::~Solver()
{
}
