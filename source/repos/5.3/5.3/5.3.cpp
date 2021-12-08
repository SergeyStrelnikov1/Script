#include "Matr3Diag.h"

using namespace std;
int main() {
	setlocale(LC_ALL, "ru");
	Matr3Diag matrA;
	matrA.input(3);
	Matr3Diag matrB;

	cin >> matrB;

	cout << "matrA:" << endl;
	cout << matrA << endl;

	cout << "matrB:" << endl;
	cout << matrB << endl;

	cout << "matrA += matrB" << endl;
	matrA += matrB;
	cout << matrA << endl;

	cout << "matrA -= matrB" << endl;
	matrA -= matrB;
	cout << matrA << endl;

	cout << "matrA += matrB" << endl;
	matrA += matrB;
	cout << matrA << endl;

	cout << "matrA + matrB" << endl;
	cout << matrA + matrB << endl;
	cout << "matrA - matrB" << endl;
	cout << matrA - matrB << endl;
	cout << "-matrA" << endl;
	cout << (-matrA) << endl;
	cout << "matrA * matrB" << endl;
	cout << matrA * matrB << endl;
	cout << "matrA * 5" << endl;
	cout << matrA * 5 << endl;
	cout << "matrB det()" << endl;
	cout << matrB.det() << endl;
	cout << "matrB trace()" << endl;
	cout << matrB.trace() << endl;
}