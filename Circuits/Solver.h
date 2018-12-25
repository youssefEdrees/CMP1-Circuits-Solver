#pragma once
#include <vector>
#include "Element.h"
#include "eigen/Eigen/Dense"
using namespace Eigen;
using namespace std;
#define MAX 100
class Solver
{

	int numOfNodes;
	Element * elements[MAX];
	Element * voltageSources[MAX];
	int elementsCount;
	int VSCount;

public:
	Solver();

	Element * getElements(int size);
	Element * getVSs(int size);
	void execute();
	void firstSquare();
	float SumOfZConnected(int node);
	void secondSquare();
	void thirdSquare();
	int getElementsCount();
	//void displaySolution();
	bool isPassive(int i);
	int& getNumOfNodesByRef();
	~Solver();
};

