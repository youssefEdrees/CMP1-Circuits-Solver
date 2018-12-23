#pragma once

enum ElementType
{
	R, 
	L, 
	C, 
	V,   // Voltage source
	C,   // Current source
	VCV, // Voltage controlled voltage source
	VCC, // Voltage controlled current source
	CCV, // Current controlled voltage source
	CCC  // Current controlled current source

	/*Passive, 
	Active*/

};