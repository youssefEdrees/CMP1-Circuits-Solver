#pragma once
#include "DEFS.h"
#include "Node.h"
#include <complex>
#include <string>
//#include "Solver.h"
#include <cmath>

using namespace std;

class Element // Or Branch
{
	string ID;

	ElementType type;
	complex<float> value;

	int node1, node2;


	//--------------------- Voltage Controlled ------------------


	int firstControllingNodeID, secondControllingNodeID;
	float factor;


	//--------------------- Current Controlled ------------------
	
	string controllingElementID;



public:
	//Element();
	Element(string ID, int node1, int node2);

	void initResistor(float R, float frequency);
	void initCapacitor(float C, float frequency);
	void initInductor(float L, float frequency);
	void initVS(float V, float phi, float frequency); // Voltage source
	void initCS(float I, float phi, float frequency); // Current source


	void initVCVS(int firstControllingNode, int secondControllingNode, float factor);// Voltage controlled voltage source
	void initVCCS(int firstControllingNode, int secondControllingNode, float factor);// Voltage controlled current source
	void initCCVS(string controllingElementID, float factor);							  // Current controlled voltage source
	void initCCCS(string controllingElementID, float factor);							  // Current controlled current source

	complex<float> getCurrent();

	~Element();
};

