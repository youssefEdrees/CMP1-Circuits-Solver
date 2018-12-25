#include "pch.h"
#include "Solver.h"
#include <cmath>
#include<iostream>
using namespace std;
Solver::Solver()
{
	for (int i = 0; i < 100; i++) {
		elements[i] = NULL;
		voltageSources[i] = NULL;
	}
	
}

void Solver::execute() {
	firstSquare();
	cout << mat;
}

Element ** Solver::getElements()
{
	return &elements[0];
}

Element ** Solver::getVSs()
{
	return &voltageSources[0];
}

complex<float> Solver::SumOfZConnected(int node) {
	complex<float>sum=(0,0);
	for (int i = 0; i < elementsCount;i++) {
		if (isPassive(i)) {
			if (elements[i]->getFirstNode() == node)
				sum += pow(elements[i]->getValue(),-1);
		}
		
	}
	return sum;
}

int & Solver::getElementsCountByRef() {
	return elementsCount;
}
int & Solver::getVCByRef() {
	return VSCount;
}

complex<float> Solver::SumOfZConnectedToX(int node1, int node2) {
	complex<float>sum = (0, 0);
	for (int i = 0; i < elementsCount; i++) {
		if (isPassive(i)) {
			if ((elements[i]->getFirstNode() == node1&& elements[i]->getSecondNode() == node2)
				|| (elements[i]->getFirstNode() == node2 && elements[i]->getSecondNode() == node1))
				sum += pow(elements[i]->getValue(), -1);
		}

	}
	return sum;

}

void Solver::firstSquare() {
	int nodesCount = numOfNodes;
	mat(0, 0) = 0;
	for (int i = 0; i < nodesCount; i++) {
		for (int t = 0; t < nodesCount; t++) {
			if (i == t) {
				complex<float> sum =SumOfZConnected(i);
				mat(i, i) = sum;
			}
			else {
				complex<float> sum = SumOfZConnectedToX(i,t);
				mat(i, t) = sum;
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

int & Solver::getNumOfNodesByRef()
{
	return numOfNodes;
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
