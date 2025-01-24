#include "Matrix.h"
#include "MatrixOperations.h"
#include "GaussMethod.h"
#include "Counter.h"
#include <time.h>
#include <iostream>
using namespace std;
int main() {
    srand(time(0));
    // Matrix mat = Matrix(3); 
    // mat.Augment();
    // GaussMethod::ReduceToREF(mat);
    // cout << "add/sub is " << Counter::addSubCounter << endl;
    // cout << "mult/div is " << Counter::multDivCounter << endl;
    Matrix mat = Matrix(3);
    mat.Augment();
    mat.PrintMatrix();
    GaussMethod::ReduceToREF(mat);
    Counter::DisplayCounters();
    GaussMethod::BackSub(mat);
    Counter::DisplayCounters();
    
}