#include "pch.h"
#include "Element.h"



Element::Element(string ID, Node node1, Node node2) : ID(ID), node1(node1), node2(node2)
{
	
}


Element::~Element()
{

}

void Element::initResistor(float R) {
	type = ElementType::R;
	value = (R, 0);
}

void Element::initCapacitor(float C) {
	type = ElementType::C;
	//value = (0, -(1 / omega * C));
}

void Element::initInductor(float L) {
	type = ElementType::L;

}

void Element::initV(float V, float phi) {

}