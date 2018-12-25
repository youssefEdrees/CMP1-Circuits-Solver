#include "pch.h"
#include <iostream>
#include "eigen/Eigen/Dense"
#include "Element.h"
#include "Solver.h"
#include "Utility.h"
#include <vector>

using namespace std;
using namespace Eigen;

vector<Element> e;

int main()
{

	Solver* s = new Solver();

	//while (true) {

		/// 1- Messege.
		cout << "Press Enter file name to load a circuit and solve it.\n";

		/// 2- Load the file.
		string path;
		cin >> path;
		Utility::load(path, s->getElements(), s->getVSs());

		/// 3- Instanciate a new solver.
		if (s != NULL) delete s;
		//s = new Solver();

		/// 4- Display solution.
		//s->displaySolution();
	//}


	return 0;
}