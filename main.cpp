#include "Matrix.h"
#include "MatrixOperations.h"
#include "GaussMethod.h"
#include "Counter.h"
#include <iostream>
using namespace std;
int main() {
    Matrix mat = Matrix(3); 
    mat.PrintMatrix();
    GaussMethod::ReduceToREF(mat);
    cout << "add/sub " << Counter::addSubCounter << endl;
    cout << "mult/div " << Counter::multDivCounter << endl;
    mat.Augment();
    GaussMethod::BackSub(mat);
}