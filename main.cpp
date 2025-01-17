#include "Matrix.h"
#include "MatrixOperations.h"
#include "GaussMethod.h"
#include <iostream>
using namespace std;
int main() {
    Matrix mat = Matrix(5); 
    mat.PrintMatrix();
    GaussMethod::ReduceToREF(mat);
    mat.Augment();
    GaussMethod::BackSub(mat);
}