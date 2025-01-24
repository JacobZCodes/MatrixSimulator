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
        Counter::multDivCounter++;
        // cout << "Scaled element, mult/div is: " << Counter::multDivCounter << endl;
        tempScaledValues[i] = scaledNum;
    }
    
    MatrixOperations::AddRows(mat, rowToBeAddedTo, tempScaledValues);
    delete[] tempScaledValues;
    
}

void MatrixOperations::AddRows(Matrix mat, Entry* rowToBeAddedTo, float* rowToAdd) {
    for (int i=0; i<mat.numCols; ++i) {
        rowToBeAddedTo[i].value += rowToAdd[i];
        Counter::addSubCounter++;
        // cout << "Added elements, add/sub is: " << Counter::addSubCounter << endl;
        // We don't count the mult/add step if the computation leads to a 0
        if (rowToBeAddedTo[i].value == 0) {
            // cout << "Decrementing counters for 0 computation..." << endl;
            Counter::addSubCounter--;
            Counter::multDivCounter--;
            // cout << "add/sub is" << Counter::addSubCounter << endl;
            // cout << "mult/div is " << Counter::multDivCounter << endl;
        }
    }
}

bool MatrixOperations::HasFullRank(Matrix mat) {
    
}

