#include "Matrix.h"
#include "MatrixOperations.h"
#include "GaussMethod.h"
#include <iostream>
using namespace std;
int main() {
    Matrix mat = Matrix(3); 
    mat.PrintMatrix();
    GaussMethod::ReduceToREF(mat);
    mat.PrintMatrix();
    // double result = pow(100,100);
    // cout << result << endl;
    mat.Augment();

}