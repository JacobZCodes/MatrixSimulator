#include "Counter.h"
#include "MatrixOperations.h"
#include "GaussMethod.h"
#include <iostream>
using namespace std;
void MatrixOperations::ScaleRow(Matrix mat, int rowIndex, float scalar) {
    for (int i=0; i<mat.numCols; ++i) {
        mat.grid[rowIndex][i].value *= scalar;
    }
}

void MatrixOperations::SwapRows(Matrix mat, int row1Index, int row2Index) {
    Entry* row2OG = mat.grid[row2Index];
    mat.grid[row2Index] = mat.grid[row1Index];
    mat.grid[row1Index] = row2OG;
}

void MatrixOperations::CombineRowsWithScalar(Matrix mat, Entry* rowToBeAddedTo, Entry* rowToBeScaled, float scalar) {
    float* tempScaledValues = new float[mat.numCols];
    for (int i=0; i<mat.numCols; ++i) {
        float scaledNum = rowToBeScaled[i].value * scalar;
        tempScaledValues[i] = scaledNum;
    }
    // update multiply/divide counter
    cout << "mult updated" << endl;
    Counter::multDivCounter += 3;
    cout << Counter::multDivCounter << endl;
    MatrixOperations::AddRows(mat, rowToBeAddedTo, tempScaledValues);
    delete[] tempScaledValues;
    
}

void MatrixOperations::AddRows(Matrix mat, Entry* rowToBeAddedTo, float* rowToAdd) {
    for (int i=0; i<mat.numCols; ++i) {
        rowToBeAddedTo[i].value += rowToAdd[i];
    }
    cout << "add updated" << endl;
    cout << "num cols is " << mat.numCols << endl;
    Counter::addSubCounter += 3;
    cout << Counter::addSubCounter << endl;
}

bool MatrixOperations::HasFullRank(Matrix mat) {
    
}

