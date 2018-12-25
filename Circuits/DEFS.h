#pragma once

enum ElementType
{
	R, 
	L, 
	C, 
	VS,   // Voltage source
	CS,   // Current source
	VCVS, // Voltage controlled voltage source
	VCCS, // Voltage controlled current source
	CCVS, // Current controlled voltage source
	CCCS  // Current controlled current source

	/*Passive, 
	Active*/

};