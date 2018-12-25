#include "pch.h"
#include <iostream>
#include "eigen/Eigen/Dense"
#include "Element.h"
#include "Solver.h"
#include "Utility.h"

using namespace std;
using namespace Eigen;

int main()
{

	Matrix3f A;
	Vector3f b;
	A << 1, 2, 3, 4, 5, 6, 7, 8, 10;
	b << 3, 3, 4;
	cout << "Here is the matrix A:\n" << A << endl;
	cout << "Here is the vector b:\n" << b << endl;
	Vector3f x = A.colPivHouseholderQr().solve(b);
	cout << "The solution is:\n" << x << endl;



	Solver* s = NULL;

	Utility::fileDialog();

	//while (true) {

		/// 1- Messege.
		cout << "Press Enter to load a circuit and solve it.";

		/// 2- Load the file.

		/// 3- Instanciate a new solver.
		if (s != NULL) delete s;
		//s = new Solver();

		/// 4- Display solution.
		//s->displaySolution();
	//}

	if (s != NULL) delete s;

	return 0;
}