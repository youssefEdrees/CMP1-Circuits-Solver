#include "pch.h"
#include "Solver.h"


Solver::Solver()
{
	for (int i = 0; i < 100; i++) {
		elements[i] = NULL;
		voltageSources[i] = NULL;
	}
	
}

Element * Solver::getElements(int  size)
{
	elementsCount = size;
	return elements[0];
}

Element * Solver::getVSs(int size)
{
	VSCount = size;
	return voltageSources[0];
}

float Solver::SumOfZConnected(int node) {
	for (int i = 0; i < elementsCount;i++) {
		if (isPassive(i)) {
			if(elements[i])
		
		}
		
	}




}

void Solver::firstSquare() {
	int nodesCount = 0;
	for (int i = 0; i < nodesCount; i++) {
		for (int t = 0; t < nodesCount; t++) {
			if (i == t) {
				
				
				
			}
		
		
		
		
		}
	
	}




}

bool Solver::isPassive(int i) {
	if (elements[i]->getType() == R || elements[i]->getType() == L || elements[i]->getType() == C)
		return true;
	else
		return false;
}

int Solver::getElementsCount() {
	int passiveCount = 0;
	for(int i=0; i<elementsCount;i++)
		if(isPassive(i))
			passiveCount++;

	return passiveCount;
}

Solver::~Solver()
{
}
