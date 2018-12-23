#pragma once
#include "DEFS.h"
#include "Node.h"
#include <complex>
#include <string>

using namespace std;

class Element // Or Branch
{
	string ID;

	ElementType type;
	complex<float> value;

	Node node1, node2;

public:
	Element(string ID, Node node1, Node node2);

	void initResistor(float R);
	void initCapacitor(float C);
	void initInductor(float L);
	void initV(float V, float phi);															  // Voltage source
	void initC(float C, float phi);															  // Current source
	void initVCV(int firstControllingNodeID, int secondControllingNodeID, float factor);	  // Voltage controlled voltage source
	void initVCC(int firstControllingNodeID, int secondControllingNodeID, float factor);	  // Voltage controlled current source
	void initCCV(string controllingElementID, float factor);								  // Current controlled voltage source
	void initCCC(string controllingElementID, float factor);								  // Current controlled current source

	complex<float> getCurrent();

	~Element();
};

