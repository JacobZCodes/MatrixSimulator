#include "Matrix.h"
#include "MatrixOperations.h"
#include "GaussMethod.h"
#include <iostream>
using namespace std;
int main() {
    Matrix mat = Matrix(100); 
    mat.PrintMatrix();
    GaussMethod::ReduceToREF(mat);
    mat.PrintMatrix();

}