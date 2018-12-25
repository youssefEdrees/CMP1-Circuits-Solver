#include "pch.h"
#include "Element.h"
#define PI 3.14159265359



Element::Element(string ID, int node1, int node2) : ID(ID), node1(node1), node2(node2)
{
	
}

//Element::Element()
//{
//
//}

Element::~Element()
{

}
ElementType Element::getType() {
	return type;
	
}

void Element::initResistor(float R, float frequency) {
	type = ElementType::R;
	value = (R, 0);
}

void Element::initCapacitor(float C, float frequency) {
	type = ElementType::C;
	value = (0, -(1 / (2 * PI * frequency * C)));
}

void Element::initInductor(float L, float frequency) {
	type = ElementType::L;
	value = (0, 2 * PI * frequency * L);
}

void Element::initVS(float V, float phi, float frequency) {
	type = ElementType::VS;
	value = (V*cos(phi), V*sin(phi));
}

void Element::initCS(float I, float phi, float frequency) {
	type = ElementType::VS;
	value = (I*cos(phi), I*sin(phi));
}

void Element::initVCVS(int firstControllingNode, int secondControllingNode, float factor)
{
	type = ElementType::VCVS;

	this->firstControllingNodeID = firstControllingNodeID;
	this->secondControllingNodeID = secondControllingNodeID;
	this->factor = factor;
}

void Element::initVCCS(int firstControllingNode, int secondControllingNode, float factor)
{
	type = ElementType::VCCS;

	this->firstControllingNodeID = firstControllingNodeID;
	this->secondControllingNodeID = secondControllingNodeID;
	this->factor = factor;
}

void Element::initCCVS(string controllingElementID, float factor)
{
	type = ElementType::CCVS;

	this->controllingElementID = controllingElementID;
	this->factor = factor;
}

void Element::initCCCS(string controllingElementID, float factor)
{
	type = ElementType::CCVS;

	this->controllingElementID = controllingElementID;
	this->factor = factor;
}

complex<float> Element::getCurrent()
{
	return complex<float>();
}
