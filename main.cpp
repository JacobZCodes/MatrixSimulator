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
    Matrix mat = Matrix(4);
    mat.Augment();
    // mat.PrintMatrix();
    GaussMethod::ReduceToREF(mat);
    Counter::ResetCounters();

    // (T) default grid for debugging
    // mat.grid[0][0].value = 1;
    // mat.grid[0][1].value = 1;
    // mat.grid[0][2].value = 1;
    // mat.grid[0][3].value = 27;

    // mat.grid[1][0].value = 0;
    // mat.grid[1][1].value = 1;
    // mat.grid[1][2].value = 3;
    // mat.grid[1][3].value = -27;


    // mat.grid[2][0].value = 0;
    // mat.grid[2][1].value = 0;
    // mat.grid[2][2].value = 2;
    // mat.grid[2][3].value = 108;
    
    // mat.PrintMatrix();
    GaussMethod::BackSub(mat);
    
}